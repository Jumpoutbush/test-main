#include <iostream>
#include <string>

// 通用函数模板
template <typename T>
void printValue(const T& value) {
    std::cout << "General print: " << value << std::endl;
}

// 函数模板全特化
template <>
void printValue<std::string>(const std::string& value) {
    std::cout << "Specialized print for std::string: " << value << std::endl;
}

template <>
void printValue<double>(const double& p){
    std::cout << "Specialized print for int* : " << p << std::endl;
}

int main() {
    printValue(42); // 调用通用模板，输出：General print: 42
    printValue(3.14); // 调用通用模板，输出：General print: 3.14
    printValue(std::string("Hello")); // 调用全特化模板，输出：Specialized print for std::string: Hello
    return 0;
}