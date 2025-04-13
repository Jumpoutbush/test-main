#include <iostream>
#include <functional>
#include <any>

template <typename... Args>
std::any callAnyFunction(std::function<std::any(Args...)> func, Args... args){
    return func(args...);
}

int add(int a, int b){
    return a + b;
}

std::string greet(const std::string& name){
    return "Hello, " + name;
}

int main(){
    auto result1 = callAnyFunction(add, 5, 3);
    std::cout << result1;

    auto result2 = callAnyFunction(greet, "World");
    std::cout << "Result of greet: " << std::any_cast<std::string>(result2) << std::endl;

    return 0;
}