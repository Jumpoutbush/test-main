#include <iostream>
#include <thread>
#include <condition_variable>

std::mutex mtx;  // 互斥量
std::condition_variable cv;  // 条件变量
bool isReady = false;  // 条件

void thread_function()
{
    std::unique_lock<std::mutex> lock(mtx);
    while (!isReady) 
    {
        cv.wait(lock);  // 等待条件满足
    }
    std::cout << "Thread is notified" << std::endl;
}

int main()
{
    std::thread t(thread_function);

    // 模拟一段耗时操作
    std::this_thread::sleep_for(std::chrono::seconds(2));

    {
        std::lock_guard<std::mutex> lock(mtx);
        isReady = true;  // 设置条件为true
    }
    cv.notify_one();  // 通知等待的线程

    t.join();
    system("pause");
    return 0;
}
