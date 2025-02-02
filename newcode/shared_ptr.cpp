#include <iostream>
#include <atomic>

template <typename T>
class SharedPtr{
private:
    T* ptr;     // 指向资源的指针
    std::atomic<std::size_t>* refCount;     // 指向控制块的指针

    void release(){
        if(refCount && refCount->fetch_sub(1, std::memory_order_acq_rel) == 1){
            delete ptr;
            delete refCount;
        }
    }
public:
    SharedPtr():ptr(nullptr), refCount(nullptr){}

    // 不希望出现 shared_ptr<int> sp = new int(200); 禁止类型转换
    explicit SharedPtr(T* p) : ptr(p), 
        refCount(p ? new std::atomic<std::size_t>(1) : nullptr){  // 堆上创建引用计数器
    }

    ~SharedPtr(){
        release();
    }

    // 拷贝构造函数
    SharedPtr(const SharedPtr<T>& other) : ptr(other.ptr), refCount(other.refCount){
        if(refCount){
            refCount->fetch_add(1, std::memory_order_relaxed);  // relaxed不构成同步关系，因为+操作不涉及到销毁对象，所以不用考虑竞态问题
        }
    }

    // 拷贝复制构造函数
    SharedPtr<T>& operator=(const SharedPtr<T>& other){
        if(this != &other){
            // 把this的资源释放掉
            release();  
            // 再把this变成other
            ptr = other.ptr;  
            refCount = other.refCount;
            if(refCount){
                refCount->fetch_add(1);
                }
        }
        return *this;   // *this是指针解引用，代表当前对象本身而不是指针，类型是T&，即当前对象的引用
    }

    // 移动构造函数
    SharedPtr(SharedPtr&& other) noexcept : ptr(other.ptr), refCount(other.refCount) {
        other.ptr = nullptr;
        other.refCount = nullptr;
    }

    // 移动赋值运算符
    // 使用标准库中的某些操作vector.swap，要求移动操作是noexcept的，以确保异常安全

    SharedPtr<T>& operator=(SharedPtr&& other) noexcept {
        if (this != &other) {
            release();  // 释放当前资源

            ptr = other.ptr;
            refCount = other.refCount;

            other.ptr = nullptr;
            other.refCount = nullptr;
        }
        return *this;
    }



    // const在成员函数后面修饰this指针。本身this指针不能修改指向，const修饰完指针就变成指针常量，不能修改指针指向对象的状态
    // 比如ptr不能修改refCount！
    T* get() const {
        return ptr;
    }

    T& operator*() const{
        return *ptr;
    }

    T* operator->() const{
        return ptr;
    }
    int use_count() const{
        // return (refCount ? *refCount : 0);
        return refCount ? refCount->load(std::memory_order_acquire):0;
    }
};
class MyClass {
public:
    MyClass() { std::cout << "MyClass constructed.\n"; }
    ~MyClass() { std::cout << "MyClass destroyed.\n"; }
    void display() const { std::cout << "Hello from MyClass.\n"; }
};

int main() {
    // 创建 SharedPtr 并管理 MyClass 对象
    SharedPtr<MyClass> ptr1(new MyClass());

    // 使用智能指针访问对象
    ptr1->display();
    std::cout << "Reference count after ptr1 creation: " << ptr1.use_count() << "\n";

    // 拷贝构造
    SharedPtr<MyClass> ptr2 = ptr1;
    std::cout << "Reference count after ptr2 copy construction: " << ptr1.use_count() << "\n";

    // 拷贝赋值
    SharedPtr<MyClass> ptr3;
    ptr3 = ptr2;
    std::cout << "Reference count after ptr3 copy assignment: " << ptr1.use_count() << "\n";

    // 移动构造
    SharedPtr<MyClass> ptr4 = std::move(ptr3);
    std::cout << "Reference count after ptr4 move construction: " << ptr4.use_count() << "\n";

    // 移动赋值
    SharedPtr<MyClass> ptr5;
    ptr5 = std::move(ptr4);
    std::cout << "Reference count after ptr5 move assignment: " << ptr5.use_count() << "\n";

    // 退出作用域，自动销毁
    return 0;
}