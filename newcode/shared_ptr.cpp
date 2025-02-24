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

    // 不希望出现 shared_ptr<int> sp = new int(200); 禁止隐式类型转换
    // 只能通过 shared_ptr<int> sp = shared_ptr<int>(new int(200)); 显式类型转换
    // 接受原始指针的构造函数
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
                refCount->fetch_add(1, std::memory_order_relaxed);
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

    void reset(T* p = nullptr) noexcept {
        release();
        ptr = p;
        refCount = new std::atomic<std::size_t>(1);
    }

    int use_count() const{
        // return (refCount ? *refCount : 0);
        return refCount ? refCount->load(std::memory_order_acquire):0;
    }
};

class Test {
public:
    Test(int val) : value(val) {
        std::cout << "Test Constructor: " << value << std::endl;
    }
    ~Test() {
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
    // SharedPtr<Test>* sp = new SharedPtr<Test>(new Test(10));
    SharedPtr<Test> sp1(new Test(100));
    std::cout << "sp1 use_count: " << sp1.use_count() << std::endl;
    sp1->show();

    SharedPtr<Test> sp2 = sp1;
    std::cout << "After sp2 = sp1:" << std::endl;
    std::cout << "sp1 use_count: " << sp1.use_count() << std::endl;
    std::cout << "sp2 use_count: " << sp2.use_count() << std::endl;

    SharedPtr<Test> sp3;
    sp3 = sp2;
    std::cout << "After sp3 = sp2:" << std::endl;
    std::cout << "sp1 use_count: " << sp1.use_count() << std::endl;
    std::cout << "sp2 use_count: " << sp2.use_count() << std::endl;
    std::cout << "sp3 use_count: " << sp3.use_count() << std::endl;

    sp2.reset(new Test(200));
    std::cout << "After sp2.reset(new Test(200)):" << std::endl;
    std::cout << "sp1 use_count: " << sp1.use_count() << std::endl;
    std::cout << "sp2 use_count: " << sp2.use_count() << std::endl;
    std::cout << "sp3 use_count: " << sp3.use_count() << std::endl;
    sp2->show();

    std::cout << "Exiting main..." << std::endl;
    return 0;
}