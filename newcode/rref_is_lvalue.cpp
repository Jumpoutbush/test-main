#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    float f = 22.43543;
    int&& ref = 10;
    //  右值引用是左值，是可以取地址的
    int* ptr = &ref;
    cout << setprecision(3) << f << " " << ref << " " << std::hex << ptr << endl;
    getchar();
    return 0;
}