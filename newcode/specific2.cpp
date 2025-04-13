#include <iostream>
#include <string>

// 通用 Pair 类模板
template <typename T, typename U>
class Pair {
public:
    T first;
    U second;

    Pair(T a, U b) : first(a), second(b) {}

    void print() const {
        std::cout << "Pair: " << first << ", " << second << std::endl;
    }
};

// 类模板偏特化：当第二个类型是指针时
template <typename T, typename U>
class Pair<T, U*> {
public:
    T first;
    U* second;

    Pair(T a, U* b) : first(a), second(b) {}

    void print() const {
        std::cout << "Pair with pointer: " << first << ", " << *second << std::endl;
    }
};

template <typename T, typename U>
class Pair<T, U&> {
public:
    T first;
    U& second;
    Pair(T a, U& b): first(a), second(b){}
    void print() const{
        std::cout << "Pair with pointer: " << first << ", " << second << std::endl;
    }
};

int main() {
    Pair<int, double> p1(1, 2.5);
    p1.print(); // 输出：Pair: 1, 2.5

    double value = 3.14;
    Pair<std::string, double*> p2("Pi", &value);
    p2.print(); // 输出：Pair with pointer: Pi, 3.14

    double val = 3.14;
    Pair<std::string, double&> p3("Pi", val);
    p3.print();
    system("pause");
    return 0;
}