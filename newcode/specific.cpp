#include <iostream>
#include <string>

// 通用类模板
template <typename T>
class Printer {
public:
void print(const T& value) {
    std::cout << "General Printer: " << value << std::endl;
}
};

// 类模板全特化
template <>
class Printer<std::string> {
public:
void print(const std::string& value) {
    std::cout << "String Printer: " << value << std::endl;
}
};

int main() {
    Printer<int> intPrinter;
    intPrinter.print(100); // 输出：General Printer: 100

    Printer<std::string> stringPrinter;
    stringPrinter.print("Hello, World!"); // 输出：String Printer: Hello, World!

    return 0;
}