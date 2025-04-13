#include <iostream>
#include <string>

template <typename T>
class Printer{
public:
    void print(const T& val){
        std::cout << "General Printer: " << val << std::endl;
    }
};

template <>
class Printer<std::string> { 
public:
    void print(const std::string& str){
        std::cout << "String Printer: " << str << std::endl;
    }
};

int main(){
    Printer<int> intPrinter;
    intPrinter.print(100);

    Printer<std::string> strPrinter;
    strPrinter.print("hello");

    system("pause");
    return 0;
}