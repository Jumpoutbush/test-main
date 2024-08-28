#include<bits/stdc++.h>
using namespace std;
double cf(double a, int b)
{
    if(b == 1) return a;
    return a*cf(a, b-1);
}
double f = 2500;
double calgap(double x)
{
    double res;
    res = f/cf(x,1)+f/cf(x,2)+f/cf(x,3)+
        f/cf(x,4)+f/cf(x,5);
    return 5000.0-res;
}
int main()
{
    double x = 1.41;
    for(x;x < 1.42;x+=0.001)
    {
        double cur = calgap(x);
        cout << cur <<endl;
    }
    system("pause");
    return 0;
}