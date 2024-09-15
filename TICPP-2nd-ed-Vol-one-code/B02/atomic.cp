#include<iostream>
#include<thread>
#include<cmath>
#include<vector>
#include<chrono>
#include<cstdlib>
#include<ctime>
#include<atomic>
 
class Counter{
public:
    void addCount() {m_count++;}
    int count() const {return m_count;}
    Counter() : m_count{0} {}
    
private:
    int m_count;
};
int work(int a){
    return a + a;
}
template<class Iter>
void realWork(Counter& c, double& totalValue, Iter b, Iter e){
    for(; b != e; ++b){
        totalValue += work(*b);
        c.addCount();
    }
}

int main()
{
    unsigned int n = std::thread::hardware_concurrency();
    std::cout << n << " concurrent threads are supported.\n";
    std::vector<int> vec;
    double totalValue = 0;
    for(int i = 0; i < 1000000; ++i){
        vec.push_back(rand() % 100);
    }
    Counter counter;
    realWork(counter, totalValue, vec.begin(),vec.end());

    std::cout << "total times: " << counter.count() << " "<< totalValue << std::endl;

    totalValue = 0;//refresh
    //multi(3) thread
    Counter counter2;
    auto iter = vec.begin() + (vec.size() / 3);
    auto iter2 = vec.begin() + (vec.size() / 3 * 2);

    std::thread b([&counter2, &totalValue, iter, iter2]{
        realWork(counter2, totalValue, iter, iter2);
    });
    auto end = vec.end();
    Counter c3;
    double totalC = 0;
    std::thread c([&c3, &totalC, iter2, end]{
        realWork(c3, totalValue, iter2, end);
    }
    );

    b.join();
    c.join();
    
    std::cout << "total times use multithread: " << c3.count() << " "<< totalValue << std::endl;
    system("pause");
}