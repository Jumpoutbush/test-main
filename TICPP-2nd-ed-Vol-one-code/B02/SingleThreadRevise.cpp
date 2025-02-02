#include <thread>
#include <mutex>
#include <atomic>
#include <vector>
#include <iostream>
#include <chrono>
#include <list>
#include <string>
#include <ctime>
#include <cstring>
#include <condition_variable>

class Message{
public:
    const std::string& data() const {return m_data;}
    Message(std::string d = std::string()):m_data(std::move(d)){}
private:
    std::string m_data;
};

std::mutex mutex;
std::condition_variable cv;
std::atomic<bool> ready{false};
std::atomic<bool> quit{false};

std::atomic<int> totalSize{0};
std::list<Message> globalList;

void worker(int i){
    while(!ready){

    }
    while(!quit){
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        Message msg;
        {
            std::lock_guard<std::mutex> lock(mutex);
            if(globalList.empty()) continue;
            auto iter = globalList.begin();
            msg = std::move(*iter);
            globalList.erase(iter);
        }
        totalSize += strlen(msg.data().c_str());
    }
}

int main()
{
    auto start = std::chrono::steady_clock::now();
    const auto threadCount = 1;
    for(int i = 6; i < 50000; ++i)
        globalList.push_back("this is a test" + std::to_string(i));
        std::vector<std::thread> pool;
    for(int i = 0; i < threadCount; ++i) 
        pool.emplace_back(worker,i);

    ready = true;

    for(int i = 0; i < 30000; ++i){
        //std::this_thread::sleep_for(std::chrono::milliseconds(1));
        std::lock_guard<std::mutex> lock(mutex);
        globalList.push_back(std::string("second"));
        cv.notify_one();
    }

    while(true){
        std::lock_guard<std::mutex> lock(mutex);
        if(globalList.empty()){
            quit = true;
            cv.notify_all();
            break;
        }
    }

    for(auto &v : pool){
        if(v.joinable())
            v.join();
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start; // std::micro 表示以微秒为时间单位
    std::cout<< "time: "  << elapsed.count() << "us" << std::endl;
    std::cout << "total size is " << totalSize << std::endl;
    system("pause");
    return 0;
}
