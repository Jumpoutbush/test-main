#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() { std::cout << "MyClass constructor" << std::endl; }
    ~MyClass() { std::cout << "MyClass destructor" << std::endl; }
    void doSomething() { std::cout << "Doing something..." << std::endl; }
};

int main() {
    // 创建一个 shared_ptr
    std::shared_ptr<MyClass> sharedPtr = std::make_shared<MyClass>();

    // 创建一个 weak_ptr 并指向 sharedPtr 所管理的对象
    std::weak_ptr<MyClass> weakPtr = sharedPtr;

    // 使用 lock() 从 weakPtr 创建一个新的 shared_ptr
    std::shared_ptr<MyClass> newSharedPtr = weakPtr.lock();
    if (newSharedPtr) {
        std::cout << "Object is still alive." << std::endl;
        newSharedPtr->doSomething();
    } else {
        std::cout << "Object has been destroyed." << std::endl;
    }

    // 释放 sharedPtr
    sharedPtr.reset();

    // 再次尝试使用 lock() 创建 shared_ptr
    newSharedPtr = weakPtr.lock();
    if (newSharedPtr) {
        std::cout << "Object is still alive." << std::endl;
        newSharedPtr->doSomething();
    } else {
        std::cout << "Object has been destroyed." << std::endl;
    }
    return 0;
}