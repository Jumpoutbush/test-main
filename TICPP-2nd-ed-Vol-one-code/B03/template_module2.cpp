#include <iostream>
using namespace std;
template<typename T>
class Compare
{   //只是把类里的函数参数泛化了而已
private:
    T t1, t2;
public:
    Compare(T a, T b): t1(a), t2(b){}
    T max() {return t1 > t2 ? t1 : t2;}
    T min() {return t1 < t2 ? t1 : t2;}
};
int main()
{
    Compare<int> c1(1, 2);
    c1.max();
    Compare<double> c2(1.2, 3.4);
    c2.min();
}