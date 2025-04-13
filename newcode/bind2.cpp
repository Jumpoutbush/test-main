#include <iostream>
#include <functional>
using namespace std;

int add(int a, int b){
    return a + b;
}

int main()
{
    auto addTwo = bind(&add, placeholders::_1, 2);
    cout << addTwo(3) << endl; // 5
    getchar();
    return 0;
}