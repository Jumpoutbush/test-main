#include <condition_variable>
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

static int i = 0;

class Print{
public:
    Print(int maxn_) : maxn(maxn_){}
    void printodd(){
        while(i < maxn){
            unique_lock<mutex> lock(mtx);
            cond.wait(lock, [this]{
                return i % 2 == 1 && i <= maxn;
            });
            if(i > maxn) return;
            cout << i << " ";
            i++;
            cond.notify_one();
        }
    }
    void printeve(){
        while(true){
            unique_lock<mutex> lock(mtx);
            cond.wait(lock, [this]{
                return i % 2 == 0 && i <= maxn;
            });
            if(i > maxn) return;
            cout << i << " ";
            i++;
            cond.notify_one();
        }
    }
private:
    mutex mtx;
    condition_variable cond;
    int maxn = 10;
};

int main()
{
    Print* printer = new Print(100);
    thread t1(&Print::printodd, printer);
    thread t2(&Print::printeve, printer);
    t1.join();
    t2.join();

    system("pause");
    return 0;
}