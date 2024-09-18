#include<thread>
#include<mutex>
#include<atomic>
#include<vector>
#include<iostream>
#include<chrono>

std::mutex mutex;
std::atomic<bool> ready{false};

void worker(int i)
{
    while(!ready){
        
        std::this_thread::sleep_for(std::chrono::seconds(1));
        //std::this_thread::yield();
    }
    //std::lock_guard<std::mutex> lock(mutex);
    std::cout << "hello world " << i << "\n";
}

int main()
{
    const auto threadCount = 4;
    std::vector<std::thread> pool;
    for(int i = 0; i < threadCount; ++i){
        pool.emplace_back(worker, i);
    }
    
    std::this_thread::sleep_for(std::chrono::minutes(2));
    ready = true;

    for(auto& v: pool){
        if(v.joinable()) 
            v.join();
    }
    std::cout << "byebye\n";
    system("pause");
}
