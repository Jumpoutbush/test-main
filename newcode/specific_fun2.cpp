#include <iostream>
#include <string>

// 通用函数模板
template <typename T>
void printValue(const T& value) {
    std::cout << "General print: " << value << std::endl;
}

template <typename T, typename... Args>
void printValue(const T& first, const Args&... args) {
    std::cout << first << " ";
    printValue(args...);
}

template <typename... Args>
void coutAll(const Args&... args){
    ((std::cout << args << " "), ...);
}

template <typename... Args>
auto sum(Args... args)->decltype((args + ...)){
    return (args + ...);
}

int main() {
    coutAll(1, 2.5, "Hello", 'A'); // 输出：1 2.5 Hello A 
    std::cout << sum(1, 2.3, 4, 5.04) << std::endl;
    system("pause");
    return 0;
}
