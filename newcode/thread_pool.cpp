#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <iostream>

using Task = std::function<void()>;
class ThreadPool{
private:
    // 工作线程向量
    std::vector<std::thread> workers;
    // 任务队列
    std::queue<Task> tasks;
    std::mutex queueMutex;
    std::condition_variable condition;
    bool stop;
public:
    explicit ThreadPool(size_t numThreads) : stop(false)
    {
        for(size_t i = 0; i < numThreads; ++i){
            workers.emplace_back([this]{
                this->workerThread();
            });
        }
    }
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
        while(true){
            Task task;
            {
                std::unique_lock<std::mutex> lock(this->queueMutex);
                // 等待任务或停止信号
                this->condition.wait(lock, [this]{
                    return this->stop || !this->tasks.empty();
                });
                if(this->stop && this->tasks.empty()){
                    return;
                }
                task = std::move(this->tasks.front());
                this->tasks.pop();
            }
            // 无需锁，因为只有任务队列需要线程安全
            task();
        }
    }
};

int main() {
    ThreadPool pool(4);
    auto task1 = []() {
        std::cout << "Task 1 is running" << std::endl;
    };
    auto task2 = []() {
        std::cout << "Task 2 is running" << std::endl;
    };
    pool.enqueue(task1);
    pool.enqueue(task2);
    system("pause");
    return 0;
}