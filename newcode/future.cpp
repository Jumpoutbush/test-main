#include <iostream>
#include <thread>
#include <future>

bool blfunc(int a){
    return a ? true : false;
}
int main()
{
    std::future<bool> blresult = std::async(std::launch::async, blfunc, 0);
    bool result = blresult.get();
    std::cout << (result ? "true" : "false");
    getchar();
    return 0;
}