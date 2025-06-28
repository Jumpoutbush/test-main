#include "Singleton.h"

int main() {
    TestSingleton::Init();
    // 获取单例实例
    std::shared_ptr<TestSingleton> instance1 = TestSingleton::GetInstance();
    std::shared_ptr<TestSingleton> instance2 = TestSingleton::GetInstance();

    // 验证是否为同一个实例
    if (instance1 == instance2) {
        std::cout << "Both instances are the same." << std::endl;
    } else {
        std::cout << "Instances are different, singleton implementation failed." << std::endl;
    }

    // 调用测试类的特有方法
    instance1->print();

    // 打印实例地址
    instance1->PrintAddress();
    instance2->PrintAddress();
    system("pause");
    return 0;
}