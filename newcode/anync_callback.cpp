#include <iostream>
#include <future>
#include <functional>
#include <thread>
#include <chrono>

int asyncTask(){
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 42;
}

void print(int result){
    std::cout << "result: " << result << std::endl;
}

// 封装异步任务和回调处理
void performAsyncTask(std::function<void(int)> callback){
    std::promise<int> promise;
    std::future<int> future = promise.get_future();

    std::thread([&promise]{
        int result = asyncTask();
        promise.set_value(result);
    }).detach();

    future.wait();
    int result = future.get();
    callback(result);
}

int main()
{
    performAsyncTask(print);
    std::cout << "do something else..." << std::endl;
    // 为了让主线程等待一段时间，方便看到异步任务的输出
    std::this_thread::sleep_for(std::chrono::seconds(3));
    system("pause");
    return 0;
}