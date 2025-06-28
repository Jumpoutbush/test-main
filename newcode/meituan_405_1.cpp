#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll binarypow(int a, int b){
    ll ans = 1;
    while(b > 0){
        if(b & 1){
            ans *= a;
        }
        a = a * a;
        b /= 2;
    }
    return ans;
}
int main()
{
    int T;
    cin >> T;
    cout << binarypow(2, 13);
    for(int z = 0; z < T; z++){
        ll n, m;
        int w2, w3;
        cin >> n >> m >> w2 >> w3;
        // 令 n >= m
        // n * binarypow(2, a) * binarypow(3, b) >= m
        int cost = INT_MAX;
        for(int i = 0; i < 32; i++){
            for(int j = 0; j < 32; j++){
                ll tmp = n * binarypow(2, i) * binarypow(3, j);
                if(tmp >= m){
                    cost = min(cost, i * w2 + j * w3);
                }
            }
        }
        cout << cost << endl;
    }
    system("pause");
    return 0;
}