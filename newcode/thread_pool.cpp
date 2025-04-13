#include <condition_variable>
#include <chrono>
#include <functional>
#include <iostream>
#include <mutex>
#include <thread>
#include <ctime>
#include <vector>
#include <queue>


using Task = std::function<void(int a)>;

class threadpool{
private:
    std::vector<std::thread> workers;
    std::queue<Task> tasks;
    std::mutex queueMutex;
    std::condition_variable condition;
    bool stop;

public:
    explicit threadpool(size_t numThreads) : stop(false)
    {
        for(size_t i = 0; i < numThreads; i++){
            workers.emplace_back([this]{
                this->workthread();
            });
        }
    }

    ~threadpool()
    {
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            stop = true;
        }
        condition.notify_all();
        for(std::thread& worker : workers){
            worker.join();
        }
    }

    void enqueue(const Task& task){
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            if(stop){
                std::__throw_runtime_error("enqueue on stopping");
            }
            this->tasks.emplace(task);
        }
        condition.notify_one();
    }

    void workthread(){
        while(true)
        {
            Task task;
            {
                std::unique_lock<std::mutex> lock(this->queueMutex);
                // 等待信号量成立
                // this->condition.wait(lock, [this]{
                //     return this->stop || !this->tasks.empty();
                // });
                while(!this->stop && this->tasks.empty()){
                    this->condition.wait(lock);
                }
                if(this->stop && this->tasks.empty()){
                    return;
                }

                task = this->tasks.front();
                this->tasks.pop();
            }
            task(10);
        }
    }
};

int main()
{ 
    {
        std::mutex mtx;
        threadpool pool(3);
        auto task1 = [&mtx](int a){
            std::lock_guard<std::mutex> lk(mtx);
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            std::cout << "task1 " << a << std::endl;
        };
        auto task2 = [&mtx](int a){
            std::lock_guard<std::mutex> lk(mtx);
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            std::cout << "task2 " << a << std::endl;
        };
        pool.enqueue(task1);
        pool.enqueue(task2);
    }
    system("pause");
    return 0;
}