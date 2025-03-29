#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <iostream>

// 定义任务类型为无返回值的函数对象
using Task = std::function<void()>;
// 线程池类
class ThreadPool{
private:
    // 工作线程向量
    std::vector<std::thread> workers;
    // 任务队列 
    std::queue<Task> tasks;
    std::mutex queueMutex; // 用于保护任务队列的互斥锁
    std::condition_variable condition; // 用于线程同步的条件变量
    bool stop; // 标记线程池是否停止
public:

    // 构造函数，初始化线程池并创建指定数量的工作线程
    explicit ThreadPool(size_t numThreads) : stop(false) 
    {
        for(size_t i = 0; i < numThreads; ++i){
            workers.emplace_back([this]{
                this->workerThread();
            });
        }
    }


    // 析构函数，停止线程池并等待所有工作线程结束
    ~ThreadPool()
    {
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            stop = true;
        }
        // 通知所有线程要结束
        condition.notify_all();
        for (std::thread& worker : workers) {
            // 阻塞线程等待执行完
            worker.join();
        }
    }

    void enqueue(const Task& task)
    {
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            if(stop){
                std::__throw_runtime_error("enqueue on stopped ThreadPool");
            }
            tasks.push(task);
        }
        condition.notify_one();     // 通知消费者消费
    }

    void workerThread()
    {
        while(true)
        {
            Task task;
            {
                // 创建互斥锁，用于保护任务队列
                std::unique_lock<std::mutex> lock(this->queueMutex);
                // 等待任务或停止信号
                this->condition.wait(lock, [this]{
                    // 如果停止信号为真，或者任务队列不为空，则返回true
                    return this->stop || !this->tasks.empty();  // false: 继续等待，true: 继续执行
                });
                // 如果停止信号为真，并且任务队列为空，则返回
                if(this->stop && this->tasks.empty()){
                    return;
                }
                // 从任务队列中取出第一个任务
                task = std::move(this->tasks.front());
                // 移除任务队列中的第一个任务
                this->tasks.pop();
            }
            // 无需锁，因为只有任务队列需要线程安全
            task();
        }
    }
};

int main() {
    {
        ThreadPool pool(3);
        auto task1 = []() {
            std::cout << "Task 1 is running" << std::endl;
        };
        auto task2 = []() {
            std::cout << "Task 2 is running" << std::endl;
        };
        auto task4 = task1;
        auto task5 = task2;

        pool.enqueue(task1);
        pool.enqueue(task2);
    }
    system("pause");
    return 0;
}