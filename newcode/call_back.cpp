#include <iostream>
#include <functional>

void operate(int num, const std::function<void(int)>& callback){
    int result = num * 20;
    callback(result);
}

void show(int res){
    std::cout << "res = " << res << std::endl;
}

int main()
{
    int num = 10;
    operate(num, show);
    return 0;
}