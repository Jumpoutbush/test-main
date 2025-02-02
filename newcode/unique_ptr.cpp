#include <iostream>
#include <utility>

template <typename T>
class UniquePtr{
private:
    T* ptr;
public:
    explicit UniquePtr(T* p = nullptr) : ptr(p){}
    //  explicit 关键字主要用于修饰构造函数或类型转换运算符，以防止 隐式转换 或 意外的类型转换。它是一种避免代码意外行为的防御性编程措施。

    //  禁止拷贝构造函数和拷贝赋值运算符
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

    // 移动构造函数
    UniquePtr(UniquePtr&& other) noexcept : ptr(other.ptr){     // 必须确信函数内部不会抛出异常，noexcept只是编译时不增加异常处理从而提高效率，如若在noexcept的代码中调用了可能抛出异常的代码，将导致程序在运行时调用std::terminate()
        other.ptr = nullptr;
    }
    
    //  移动赋值运算符
    UniquePtr& operator=(UniquePtr&& other) noexcept {
        if(this != &other){
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    ~UniquePtr(){
        delete ptr;
    }

    // 获取原始指针
    T* get() const {
        return ptr;
    }

    // 释放控制权并返回原始指针
    T* release() {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }

    // 重置指针，释放旧资源
    void reset(T* p = nullptr) {
        if (ptr != p) {
            delete ptr; // 释放旧资源
            ptr = p;    // 接管新资源
        }
    }

    // 重载 `->` 操作符
    T* operator->() const {
        return ptr;
    }

    // 重载 `*` 操作符
    T& operator*() const {
        return *ptr;
    }

    // 检查是否为空
    bool operator!() const {
        return ptr == nullptr;
    }
};
class MyClass {
public:
    MyClass() { std::cout << "MyClass constructed\n"; }
    ~MyClass() { std::cout << "MyClass destroyed\n"; }
    void display() { std::cout << "Hello from MyClass\n"; }
};

int main() {
    UniquePtr<MyClass> ptr1(new MyClass()); // 创建 unique_ptr
    ptr1->display();

    // 转移所有权
    UniquePtr<MyClass> ptr2 = std::move(ptr1);
    if (!ptr1) {
        std::cout << "ptr1 is null after move\n";
    }
    ptr2->display();

    // 重置资源
    ptr2.reset(new MyClass());
    ptr2->display();

    // 释放控制权
    MyClass* rawPtr = ptr2.release();
    delete rawPtr; // 需要手动删除

    return 0; // 自动释放 ptr1 和 ptr2 的资源
}