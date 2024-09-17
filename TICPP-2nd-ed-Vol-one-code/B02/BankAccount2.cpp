/*
    问题：找一个标识符,让两个lock根据情况先后执行，如果有多方是不是要2^n次else
    解决方法：利用标准库接口
*/
#include<iostream>
#include<thread>
#include<mutex>

struct BankAccount{
    BankAccount(int b) : Balance(b){}
    int Balance;
    std::mutex Mutex;
};

template<typename T>
class Lock{
public:
    Lock(T& m) : m_mutex(m) {m.lock();}
    ~Lock() {m_mutex.unlock();}
private:
    T& m_mutex;
};

void transferMoney(BankAccount& a, BankAccount& b, int money){
    std::lock(a.Mutex, b.Mutex);//可以有若干多参数
    std::lock_guard<std::mutex> lockA(a.Mutex, std::adopt_lock);
    std::lock_guard<std::mutex> lockB(a.Mutex, std::adopt_lock);
    
    if(a.Balance <= money)
        return;
    a.Balance -= money;
    b.Balance += money;
}

int main()
{
    BankAccount a(1250), b(2250);
    transferMoney(a, b, 200);
    std::cout << a.Balance<< " " << b.Balance<< std::endl;
    system("pause");
    return 0;
}