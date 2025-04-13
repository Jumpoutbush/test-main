#include <atomic>
#include <iostream>
#include <string>
#include <memory>
#include <mutex>
using namespace std;

struct A{};
struct B{};
struct C{};

struct Adm{};
struct Tec{};
struct Fin{};

template <typename City, typename Department, int Number>
class Singleton{
private:
    static Singleton<City, Department, Number>* instance;
    Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
public:
    static Singleton<City, Department, Number>* GetInstance(){
        static std::once_flag s_flag;
        std::call_once(s_flag, [&]{
            instance = new Singleton<City, Department, Number>();
        });
        return instance;
    }

    // 模拟管理类的功能
    void manage() {
        std::string cityName;
        if(std::is_same<City, A>::value) {  // City和A是相同的类型
            cityName = "City A";
        } else if (std::is_same<City, B>::value) {
            cityName = "City B";
        } else if (std::is_same<City, C>::value) {
            cityName = "City C";
        }

        std::string departmentName;
        if (std::is_same<Department, Adm>::value) {
            departmentName = "Administration";
        } else if (std::is_same<Department, Tec>::value) {
            departmentName = "Technique";
        } else if (std::is_same<Department, Fin>::value) {
            departmentName = "Finance";
        }

        std::cout << cityName << " " << departmentName << " " << Number << " is managing." << std::endl;
    }
};

template <typename City, typename Department, int Number>
Singleton<City, Department, Number>* Singleton<City, Department, Number>::instance = nullptr;

int main(){
    // A市行政部1号管理类
    Singleton<A, Adm, 1>* mgr_a_adm_1 = Singleton<A, Adm, 1>::GetInstance();
    mgr_a_adm_1->manage();

    // B市技术部2号管理类
    Singleton<B, Tec, 2>* mgr_b_tec_2 = Singleton<B, Tec, 2>::GetInstance();
    mgr_b_tec_2->manage();

    system("pause");
    return 0;
}
