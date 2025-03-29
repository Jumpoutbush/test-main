#include <memory>
#include <mutex>
#include <iostream>

template<typename T>
class Singleton {
protected:
    Singleton() = default;
    Singleton(const Singleton<T>&) = delete;
    Singleton& operator = (const Singleton<T>&) = delete;

    static std::shared_ptr<T> _instance;
public:
    static std::shared_ptr<T> GetInstance()
    {
        static std::once_flag s_flag;
        std::call_once(s_flag, [&]{
            _instance = std::make_shared<T>();
        });
        return _instance;
    }

    void PrintAddress() 
    {
        std::cout << _instance.get() << std::endl;
    }

    ~Singleton()
    {
        std::cout << "Singleton desconstructor" << std::endl;
    }
};

template <typename T>
std::shared_ptr<T> Singleton<T>::_instance = nullptr;

class TestSingleton : public Singleton<TestSingleton> {
public:
    void print() {
        std::cout << "TestSingleton instance address: " << this << std::endl;
    }
};