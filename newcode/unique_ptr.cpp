#include <iostream>

// 空删除器
template <typename T>
struct default_delete{
    void operator()(T* ptr) const{
        delete ptr;
    }
};

// 单对象的unique_ptr
template <typename T, typename D = default_delete<T>>
class unique_ptr{
private:
    T* ptr_;
    D delete_;
    
    // 释放所管理的资源并返回原始指针
    void release() noexcept {
        if(ptr_){
            delete_(ptr_);
        }
    }
public:
    unique_ptr() noexcept : ptr_(nullptr){}

    // 接受原始指针的构造函数
    explicit unique_ptr(T* p) noexcept : ptr_(p){}

    ~unique_ptr(){
        release();
    }
    unique_ptr(const unique_ptr<T>&) = delete;
    unique_ptr& operator=(const unique_ptr<T>&) = delete;

    unique_ptr(unique_ptr<T>&& other) noexcept : ptr_(other.ptr_), delete_(std::move(other.delete_)){
        other.ptr_ = nullptr;
    }

    unique_ptr& operator=(unique_ptr<T>&& other) noexcept {
        if(this != &other){
            reset();
            ptr_ = other.ptr_;
            delete_ = std::move(other.delete_);
            other.delete_ = nullptr;
        }
        return *this;
    }

    bool operator!() const noexcept {
        return !ptr_;
    }

    T& operator*() const noexcept {
        return *ptr_;
    }
    T* operator->() const noexcept {
        return ptr_;
    }
    T* get() const noexcept {
        return ptr_;
    }

    void reset(T* p = nullptr) noexcept {
        release();
        ptr_ = p;
    }
};

class Test{
public:
    Test(int val) : value(val){
        std::cout << "Test Constructor: " << value << std::endl;
    }
    ~Test(){
        std::cout << "Test Destructor: " << value << std::endl;
    }
    void show() const {
         std::cout << "Value: " << value << std::endl;
    }
private:
    int value;
};

int main()
{
    unique_ptr<Test> ptr1(new Test(100));
    ptr1->show();

    unique_ptr<Test> ptr2(new Test(200));
    ptr2->show();

    unique_ptr<Test> ptr3 = std::move(ptr1);
    if (!ptr1) {
        std::cout << "ptr1 is now nullptr after move." << std::endl;
    }
    ptr3->show();

    // 重置 unique_ptr
    ptr2.reset(new Test(300));
    ptr2->show();

    // unique_ptr 自动释放资源
    return 0;
}