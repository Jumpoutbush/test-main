#include <iostream>
#include <functional>

using namespace std;

class Calculator{
public:
    int multiply(int a, int b){
        return a * b;
    }
};

int main()
{
    Calculator calc;
    auto multi = bind(&Calculator::multiply, &calc, 10, placeholders::_1);
    function<int(int)> multi2 = bind(&Calculator::multiply, &calc, 10, placeholders::_1);
    int result = multi2(5);
    system("pause");
    return 0;
}