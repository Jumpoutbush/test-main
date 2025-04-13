#include <iostream>
#include <memory>

class B;

class A {
public:
    std::shared_ptr<B> b_ptr;
    ~A() {
        std::cout << "A destroyed" << std::endl;
        std::cout << this->b_ptr.use_count() << std::endl;
    }
};

class B {
public:
    std::weak_ptr<A> a_ptr;
    ~B() {
        std::cout << "B destroyed" << std::endl;
        std::cout << this->a_ptr.use_count() << std::endl;
    }
};

int main() {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    // 输出创建对象后 a 和 b 的引用计数
    std::cout << "After creation:" << std::endl;
    std::cout << "a use count: " << a.use_count() << std::endl;
    std::cout << "b use count: " << b.use_count() << std::endl;

    // 建立相互引用
    a->b_ptr = b;
    b->a_ptr = a;

    // 输出建立引用后 a 和 b 的引用计数
    std::cout << "\nAfter establishing references:" << std::endl;
    std::cout << "a use count: " << a.use_count() << std::endl;
    std::cout << "b use count: " << b.use_count() << std::endl;

    return 0;
}    