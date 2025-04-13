#include <iostream>
#include <thread>
#include <future>
#include <functional>
#include <mutex>
#include <vector>
#include <queue>
#include <condition_variable>

using Task = std::function<void(int)>;

class threadPool{
private:
    std::vector<std::thread> workers;   // 取出任务工作线程
    std::queue<std::pair<Task, int>> tasks; // 任务队列
    std::mutex queueMutex;  // 保护任务队列
    std::condition_variable condition;
    bool stop;
public:
    explicit threadPool(size_t numThreads) : stop(false){
        for(size_t i = 0; i < numThreads; i++){
            workers.emplace_back([this]{
                this->workthread();
            });
        }
    }

    ~threadPool(){
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            stop = true;
        }
        condition.notify_all();
        for(std::thread& worker : workers){
            worker.join();
        }
    }

    void enqueue(const Task& task, int param){
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            if(stop){
                std::__throw_runtime_error("enqueue on stopping");
            }
            this->tasks.emplace(std::pair<Task, int>{task, param});
        }
        condition.notify_one();
    }
    void workthread(){
        while(true)
        {
            std::pair<Task, int> task;
            {
                std::unique_lock<std::mutex> lock(queueMutex);
                this->condition.wait(lock, [this]{
                    return this->stop || !this->tasks.empty(); 
                });
                if(this->stop && this->tasks.empty()){
                    return;
                }
                task = this->tasks.front();
                tasks.pop();
            }
            task.first(task.second);
        }
    }
};
void printa(int a){
    std::cout << a << std::endl;
}
int main(){
    {
        threadPool pool(2);
        pool.enqueue(printa, 5);
        pool.enqueue([](int a){
            std::cout << a * 2 << std::endl;
        }, 10);
    }
    system("pause");
    return 0;
}