#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, V;
    scanf("%d%d", &n, &V);
    vector<int> weights(n), values(n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &weights[i], &values[i]);
    }


    // 任何情况下的最大价值
    vector<int> dp(V, 0);
    for(int i = 0; i < n; i++){
        for(int v = V; v >= weights[i]; v--){
            dp[v] = max(dp[v], dp[v - weights[i]] + values[i]);
        }
    }
    printf("%d\n", dp[V]);

    // 刚好放下V个重量的最大价值
    vector<int> dpV(V, INT_MIN);
    dpV[0] = 0;  // 必须从0开始转移状态
    for(int i = 1; i < n; i++){
        for(int v = V; v >= weights[i]; v--){
            dpV[v] = max(dpV[v], dpV[v - weights[i]] + values[i]);
        }
    }
    if(dpV[V] < 0) dpV[V] = 0;
    printf("%d", dpV[V]);
    system("pause");
    return 0;
}