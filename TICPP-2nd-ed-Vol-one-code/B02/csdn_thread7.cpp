#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;  // 互斥量

void thread_function()
{
    std::unique_lock<std::mutex> lock(mtx);  // 加锁互斥量
    std::cout << "Thread running" << std::endl;
    // 执行需要加锁保护的代码
    lock.unlock();  // 手动解锁互斥量
    // 执行不需要加锁保护的代码
    lock.lock();  // 再次加锁互斥量
    // 执行需要加锁保护的代码
}  
// unique_lock对象的析构函数自动解锁互斥量

int main()
{
    std::thread t1(thread_function);
    t1.join();
    std::cout << "Main thread exits!" << std::endl;
    return 0;
}
