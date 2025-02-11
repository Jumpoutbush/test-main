#include <memory>
#include <mutex>
#include <iostream>
template <typename T>
class Singleton {
protected:
    Singleton() = default;
    Singleton(const Singleton<T>&) = delete;
    Singleton& operator=(const Singleton<T>& st) = delete;

    static std::shared_ptr<T> _instance;
public:
    static std::shared_ptr<T> GetInstance() {
        static std::once_flag s_flag;
        std::call_once(s_flag, [&](){
            _instance = std::shared_ptr<T>(new T);
        });
        return _instance;
    }
    void PrintAddress() {
        std::cout << _instance.get() << std::endl;
    }
    ~Singleton(){
        std::cout << "this is singleton destruct" << std::endl;
    }
};

/* 
    类中的_instance声明仅仅是告诉编译器 _instance是static std::shared_ptr<T> 类型的成员变量
    但并没有为其分配内存
    所以，需要在类外部进行定义
*/
template <typename T>
std::shared_ptr<T> Singleton<T>::_instance = nullptr;