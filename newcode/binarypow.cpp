#include <iostream>
using namespace std;
// a^b % m
typedef long long ll;
ll binarypow(ll a, ll b, ll m){ //递归写法很可能达不到时间复杂度
    if(b == 0) return 1;
    if(b % 2 == 1){
        return a * binarypow(a, b - 1, m) % m;
    }else{
        ll mul = binarypow(a, b / 2, m);
        return mul * mul % m;
    }
}
ll binarypow2(ll a, ll b, ll m){
    ll ans = 1;
    while(b > 0){
        if(b & 1){  // b % 2 == 1
            ans = ans * a % m;
        }
        a = a * a % m;  // 平方
        b /= 2;
    }
    return ans;
}
int main(){
    ll a = 1e6 + 8, b = 1e11 + 4, m = 1e9 + 7;
    cout << binarypow(a, b, m);
    getchar();
    return 0;
}