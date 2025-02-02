//单线程下任务转换成多线程
#include <stdlib.h>
#include <iostream>
#include <list>
#include <string>
#include <thread>
#include <chrono>
#include <ctime>
#include <cstring>

class Message{
public:
    const std::string& data()const {return m_data;}
    Message(std::string d): m_data(std::move(d)){}
private:
    std::string m_data;
};
static int totalSize = 0;
std::list<Message> globalList;
void worker(){
    while(!globalList.empty()){
        auto iter = globalList.begin();
        //do real work and erase it
        totalSize += strlen(((*iter).data().c_str()));
        globalList.erase(iter);
    }
}
int main(){
    
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < 10000; ++i)
        globalList.push_back("this is a test" + std::to_string(i));

    worker();
    
    for(int i = 0; i < 10000; ++i){
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        globalList.push_back(std::string("second"));
    }
    
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start; // std::micro 表示以微秒为时间单位
    std::cout<< "time: "  << elapsed.count() << "us" << std::endl;
    //14~15s
    worker();
    std::cout << "total size is " << totalSize << std::endl;
    system("pause");
}