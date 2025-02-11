#include <iostream>
#include <atomic>

template <typename T>
class WeakPtr;
// weakPtr不拥有对象所有权
template <typename T>
class ContorlBlock {
public:
    T* ptr;
    std::atomic<std::size_t>* ref_count;
    std::atomic<std::size_t>* weak_count;
    void release_shared(){
        if(ref_count && ref_count->fetch_sub(1, std::memory_order_acq_rel) == 1){
            if(weak_count && weak_count->fetch_sub(1, std::memory_order_acq_rel) == 1){
                delete ptr;
                delete ref_count;
                delete weak_count;
            }
        }
    }
    void release_weak(){
        if(weak_count && weak_count->fetch_sub(1, std::memory_order_acq_rel) == 1){
            if(ref_count && ref_count->load(std::memory_order_acquire)){
                delete ptr;
                delete ref_count;
                delete weak_count;
            }
        }
    }
    ContorlBlock(T* p) : ptr(p), 
        ref_count(p ? new std::atomic<std::size_t>(1) : nullptr), 
        weak_count(p ? new std::atomic<std::size_t>(0) : nullptr){}
    ~ContorlBlock(){
        release_shared();
    }
};

template <typename T>
class SharedPtr{
private:
    T* ptr;
    ContorlBlock<T>* control_block;

public:
    SharedPtr() : ptr(nullptr), control_block(nullptr){}
    explicit SharedPtr(T* p) : ptr(p){
        control_block = new ContorlBlock<T>(p);
    }
    ~SharedPtr(){
        if(control_block){
            control_block->release_shared();
        }
    }

    SharedPtr(const SharedPtr& other) : ptr(other.ptr), control_block(other.control_block){
        if(control_block){
            control_block->ref_count->fetch_add(1, std::memory_order_relaxed);
        }
    }

    SharedPtr<T>& operator=(const SharedPtr<T>& other) {
        if(this != &other){
            if(control_block){
                control_block->release_shared();
            }
        }
        ptr = other.ptr;
        control_block = other.control_block;
        if(control_block){
            control_block->ref_count->fetch_add(1, std::memory_order_relaxed);
        }
    }

    // 接受weak_ptr的构造函数
    SharedPtr(const WeakPtr<T>& other) : ptr(other.ptr), control_block(other.control_block){
        if(control_block){
            control_block->ref_count->fetch_add(1, std::memory_order_relaxed);
        }
    }

    SharedPtr(SharedPtr<T>&& other) noexcept : ptr(other.ptr), control_block(other.control_block){
        other.ptr = nullptr;
        other.control_block = nullptr;
    }

    SharedPtr<T>& operator=(SharedPtr<T>&& other) noexcept {
        if(this != &other){
            if(control_block){
                control_block->release_shared();
            }
            ptr = other.ptr;
            control_block = other.control_block;
            other.ptr = nullptr;
            other.control_block = nullptr;
        }
        return *this;
    }
    
    T& operator*() const {
        return *ptr;
    }
    T* operator->() const {
        return ptr;
    }
    T* get() const {
        return ptr;
    }

    auto use_count() const {
        return control_block ? control_block->ref_count->load(std::memory_order_acquire) : 0;
    }

    // 友元函数，用于 weak_ptr 访问 control_block
    template <typename U>
    friend class WeakPtr;
};

template <typename T>
class WeakPtr {
private:
    T* ptr;
    ContorlBlock<T>* control_block;

public:
    WeakPtr() : ptr(nullptr), control_block(nullptr){}
    ~WeakPtr(){
        if(control_block){
            control_block->release_weak();
        }
    }
    WeakPtr(const SharedPtr<T>& other) : ptr(other.ptr), control_block(other.control_block){
        if(control_block){
            control_block->weak_count->fetch_add(1, std::memory_order_relaxed);
        }
    }

    WeakPtr(const WeakPtr<T>& other) : ptr(other.ptr), control_block(other.control_block){
        if(control_block){
            control_block->weak_count->fetch_add(1, std::memory_order_relaxed);
        }
    }

    WeakPtr<T>& operator=(const WeakPtr<T>& other) {
        if(this != &other){
            if(control_block){
                if(control_block->weak_count){
                    control_block->release_weak();
                }
            }
        }
        ptr = other.ptr;
        control_block = other.control_block;
        if(control_block){
            control_block->weak_count->fetch_add(1, std::memory_order_relaxed);
        }
        return *this;
    }

    WeakPtr(WeakPtr<T>&& other) noexcept : ptr(other.ptr), control_block(other.control_block){
        other.ptr = nullptr;
        other.control_block = nullptr;
    }

    WeakPtr<T>& operator=(WeakPtr<T>&& other) noexcept {
        if(this != &other){
            if(control_block){
                control_block->release_weak();
            }
            ptr = other.ptr;
            control_block = other.control_block;
            other.ptr = nullptr;
            other.control_block = nullptr;
        }
        return *this;
    }
    
    // 从weak_ptr创建shared_ptr
    SharedPtr<T> lock() const{
        if(control_block && control_block->ref_count > 0){
            return SharedPtr<T>(*this);
        }
        return SharedPtr<T>();
    }
    
    // 检查对象是否存在
    bool expired() const {
        return control_block ? control_block->ref_count->load(std::memory_order_acquire) == 0 : true;
    }

    // 获取弱引用计数
    auto use_count() const {
        return control_block ? control_block->weak_count->load(std::memory_order_acquire) : 0;
    }

    template <typename U>
    friend class SharedPtr;
};

int main() {
    // 创建一个 shared_ptr
    SharedPtr<int> shared(new int(42));
    std::cout << "SharedPtr use count: " << shared.use_count() << std::endl;

    // 创建一个 weak_ptr 指向 shared_ptr 所管理的对象
    WeakPtr<int> weak(shared);
    std::cout << "WeakPtr use count: " << weak.use_count() << std::endl;

    // 通过 weak_ptr 获取 shared_ptr
    SharedPtr<int> another_shared = weak.lock();
    if (another_shared.use_count() > 0) {
        std::cout << "WeakPtr locked: " << *another_shared << std::endl;
    }

    // 释放 shared_ptr
    shared = SharedPtr<int>();
    std::cout << "SharedPtr released." << std::endl;

    // 再次尝试通过 weak_ptr 获取 shared_ptr
    another_shared = weak.lock();
    if (another_shared.use_count() == 0) {
        std::cout << "WeakPtr expired." << std::endl;
    }
    system("pause");
    return 0;
}