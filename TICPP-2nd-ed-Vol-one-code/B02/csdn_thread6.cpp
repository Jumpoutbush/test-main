#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex mtx;  // 互斥量

void thread_function()
{
    std::lock_guard<std::mutex> lock(mtx);  // 加锁互斥量
    std::cout << "Thread running" << std::endl; 
    // 执行需要加锁保护的代码
}  // lock_guard对象的析构函数自动解锁互斥量

int main()
{
    std::thread t1(thread_function);
    t1.join();
    system("pause");
    return 0;
}
