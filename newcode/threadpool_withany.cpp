#include <functional>
#include <future>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>
#include <condition_variable>

/*
    Args, forward & &&, bind, future, result of, function->std::future
*/
using Task = std::function<void()>;
class ThreadPool{
private:
    std::vector<std::thread> workers;
    std::queue<Task> tasks;
    std::mutex queueMutex;
    std::condition_variable condition;
    bool stop;

public:
    explicit ThreadPool(size_t numThreads) : stop(false){
        for(size_t i = 0; i < numThreads; i++){
            workers.emplace_back([this]{
                while(true)
                {
                    Task task;
                    {
                        std::unique_lock<std::mutex> lock(queueMutex);
                        this->condition.wait(lock, [this]{
                            return this->stop || !this->tasks.empty();
                        });
                        if(this->stop && this->tasks.empty()){
                            return;
                        }
                        task = std::move(tasks.front());
                        tasks.pop();
                    }
                    task();
                }
            });
        }
    }

    ~ThreadPool()
    {
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            stop = true;
        }
        condition.notify_all();
        for(auto& i : workers){
            i.join();
        }
    }

    /*
      @brief 接收任意参数任务
      方法：
            1. 可变参数模板Args...接受任意数量和类型的参数
              1.1 ->std::future，返回一个typename类型为————函数F执行过后得到的类型名type的结果
                  using return_type = ...
            2. package_task封装用户传入的函数及其参数
              2.1 用make_shared创造对象，确保在入队操作结束释放，但工作线程中还存在时仍能调用它，
                    让packaged_tas对象在所有引用它的地方都可以正常访问
                    另外future对象可用异步获取返回值 res = 防止对象被销毁
            3. std::bind绑定函数和参数
              3.1 处理右值引用F&& f,
            4. future获取返回值res
            5. 正常入队
    */
    template <class F, class... Args> 
    auto enqueue(F&& f, Args&&... args)
            -> std::future<typename std::result_of<F(Args...)>::type>
         {
            using return_type = typename std::result_of<F(Args...)>::type;
            auto task = std::make_shared<std::packaged_task<return_type()>>(
                std::bind(std::forward<F>(f), std::forward<Args>(args)...)
            );
            std::future<return_type> res = task->get_future();
            {
                std::unique_lock<std::mutex> lock(queueMutex);
                if (stop) {
                    throw std::runtime_error("enqueue on stopped ThreadPool");
                }
                tasks.emplace([task]() { (*task)(); });
            }
            condition.notify_one();
            return res;
         }
};

// 示例函数
int add(int a, int b) {
    return a + b;
}

void printMessage(const std::string& message) {
    std::cout << message << std::endl;
}

int main() {
    ThreadPool pool(2);

    // 添加有返回值的任务
    auto future1 = pool.enqueue(add, 3, 5);
    std::cout << "Result of add: " << future1.get() << std::endl;

    // 添加无返回值的任务
    pool.enqueue(printMessage, "Hello, ThreadPool!");
    system("pause");
    return 0;
}    