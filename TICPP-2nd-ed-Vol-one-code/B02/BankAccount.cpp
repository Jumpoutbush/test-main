#include<iostream>
#include<thread>
#include<mutex>

struct BankAccount{
    BankAccount(int b) : Balance(b)    {}
    int Balance;
    std::mutex Mutex;
};

template<typename T>
class Lock{
public:
    Lock(&T m) : m_mutex(m) {m.lock();}
    ~Lock() {m_mutex.unlock();}
private:
    T& m_mutex;
};

void transferMoney(BankAccount& a, BankAccount& b, int money){
    if(&a == &b) return;
    if(&(a.Mutex) < &(b.Mutex)){
        std::lock_guard<std::mutex> lockA(a.Mutex);
        std::lock_guard<std::mutex> lockB(b.Mutex);
        //需要保加锁护的代码块, a.Balance与b.Balance
        if(a.Balance <= money)
            return;
        a.Balance -= money;
        b.Balance += money;
    }else{//找一个标识符,让两个lock根据情况先后执行
        std::lock_guard<std::mutex> lockA(b.Mutex);
        std::lock_guard<std::mutex> lockB(a.Mutex);
        //需要保加锁护的代码块, a.Balance与b.Balance
        if(a.Balance <= money)
            return;
        a.Balance -= money;
        b.Balance += money;
    }
}

int main()
{

}