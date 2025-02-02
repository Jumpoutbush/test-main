#include <iostream>
#include <functional>

void print(){
    std::cout << "Hello I am XYZ" << std::endl;
}

void func(std::function<void()>& cb){
    std::cout << "Address after function input:" << &cb << std::endl;
    std::cout << "Called after passing in the function" << std::endl;
    std::function<void()> call_back;
    call_back.swap(cb);
    call_back();
}

int main(int argc, char** argv){
    std::function<void()> f = print;
    std::cout << "Address before function input:" << &f << std::endl;
    func(f);
    std::cout << "Called again after passing in the function" << std::endl;
    f();
    return 0;
}
