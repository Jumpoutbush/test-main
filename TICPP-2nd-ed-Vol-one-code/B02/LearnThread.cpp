#include<iostream>
#include<thread>
#include<cmath>
#include<vector>
#include<chrono>
#include<cstdlib>
#include<ctime>

double caculate(double v){
    if(v <= 0) return v;
    //减慢
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    return v * v + std::sqrt((v + 5) * (v + 2.5)) / 2.0;
}
template<typename Iter, typename Fun>
double visitRange(std::thread::id id, Iter iterBegin, Iter iterEnd, Fun func){
    auto curId = std::this_thread::get_id();
    if(id == curId)
        std::cout << curId << "hello main thread\n";
    else 
        std::cout << curId << "hello work thread\n";
    double v = 0;
    for(auto iter = iterBegin; iter != iterEnd; ++iter){
        v += func(*iter);
    }
    return v;
}
int main()
{
    auto mainThreadId = std::this_thread::get_id();
    std::vector<double> v;
    for(int i = 0; i < 1000; ++i){
        v.push_back(rand());
    }
    std::cout << v.size() << std::endl;
    double value = 0.0;
    auto nowc = clock();
    for(auto& info : v){
        value += caculate(info);
    }
    auto finishc = clock();
    std::cout << "single thread: " << value << " used " << (finishc - nowc) << std::endl; 
    auto iter = v.begin() + (v.size() / 2);

    //second
    double anotherv = 0.0;
    auto iterEnd = v.end();
    //std::function
    std::thread s([&anotherv, mainThreadId, iter, iterEnd](){
        anotherv = visitRange(mainThreadId, iter, iterEnd, caculate);
    });

    //auto id = s.get_id();
    auto halfv = visitRange(mainThreadId, v.begin(), iter, caculate);
    //清理
    s.join();
    std::cout << "multithread: " << (halfv + anotherv) << " used " << (finishc - nowc) << std::endl;
    system("pause");
}