#include <thread>
#include <mutex>
#include <iostream>
#include <condition_variable>

void two_thread_print()
{
    std::mutex mtx;                 // 创建一个互斥锁
    std::condition_variable c;      // 创建一个条件变量
    int n = 100;                    // 打印的最大数值
    bool flag = true;               // 初始时打印偶数

    // 创建线程 t1，用于打印偶数
    std::thread t1([&](){
        int i = 0;
        while (i < n)
        {
            std::unique_lock<std::mutex> lock(mtx);   // 加锁，必须使用 unique_lock
            c.wait(lock, [&]()->bool{return flag; }); // 等待 flag 为 true
            std::cout << i << std::endl;              // 打印偶数
            flag = false;                             // 设置 flag 为 false，表示该轮打印奇数
            i += 2;                                   // 增加偶数计数器
            c.notify_one();                           // 通知线程 t2
        }
    });

    // 创建线程 t2，用于打印奇数
    std::thread t2([&](){
        int j = 1;
        while (j < n)
        {
            std::unique_lock<std::mutex> lock(mtx);    // 加锁，必须使用 unique_lock
            c.wait(lock, [&]()->bool{return !flag; }); // 等待 flag 为 false
            std::cout << j << std::endl;               // 打印奇数
            flag = true;                               // 设置 flag 为 true，表示该轮打印偶数
            j += 2;                                    // 增加奇数计数器
            c.notify_one();                            // 通知线程 t1
        }
    });

    // 等待两个线程执行完毕
    t1.join();
    t2.join();
}

int main()
{
    two_thread_print(); // 启动两个线程交替打印奇数和偶数
    system("pause");
    return 0;
}

