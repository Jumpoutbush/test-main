#include<iostream>
#include<thread>
#include<cmath>
#include<vector>
#include<chrono>
#include<cstdlib>
#include<ctime>
#include<atomic>
#include<mutex>

class Counter{
public:
    void addCount() {m_count++;}
    int count() const {return m_count;}
    void addResource(int r) {m_totalResource++;}
    int aveResource() {
        if(m_count == 0)
            return 0;
        return m_totalResource / m_count;
    }
    Counter() : m_count{0},m_totalResource{0} {}
    void lockMutex() {m_mutex.lock();}
    void unlockmutex() {m_mutex.unlock();}
    
private:
    std::atomic<int> m_count;
    std::atomic<int> m_totalResource;
    std::mutex m_mutex;
};
int work(int a){
    return a + a;
}
void debugPrintInfo(Counter& c){
    c.lockMutex();
    std::cout << c.aveResource() << std::endl;
    c.unlockmutex();
}

void doSomeThing(){
    throw "bad";
}

template<class Iter>
void realWork(Counter& c, double& totalValue, Iter b, Iter e){
    for(; b != e; ++b){
        totalValue += work(*b);
        c.lockMutex();
        c.addCount();
        c.addResource(1);
        c.unlockmutex();
    }
}
bool printStep(Counter &c, int maxCount){
    auto count = c.count();
    c.lockMutex();
    auto ave = c.aveResource();
    if(ave != 1) std::cout << "error\n";
    c.unlockmutex();
    if(count == maxCount){
        std::cout << " ok finished \n";
        return true;
    }
    return false;
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
    double totalC = 0;
    std::thread c([&counter2, &totalC, iter2, end]{
        realWork(counter2, totalC, iter2, end);
    }
    );

    double totalM = 0;
    realWork(counter2, totalM, vec.begin(), iter);
    b.join();
    c.join();
    auto realTotalCount = counter2.count();
    totalValue += totalC + totalM;
    std::cout << "total times use multithread: " << realTotalCount << " "<< totalValue << std::endl;
    system("pause");
}