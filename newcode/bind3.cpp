#include <iostream>
#include <functional>
using namespace std;

int main(){
    auto func = bind([](int a, int b){return a + b;}, placeholders::_1, 10);
    cout << func(20) << endl; // 30
    getchar();
    return 0;
}