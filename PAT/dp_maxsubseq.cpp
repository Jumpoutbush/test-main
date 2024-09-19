#include<bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int A[maxn], dp[maxn];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    dp[0] = A[0];
    for(int i = 1; i < n; i++){
        dp[i] = max(A[i], dp[i-1] + A[i]);
    }
    int max = -1;
    for(int i = 1; i < n; i++){
        if(dp[i] > max)
            max = dp[i];
    }
    printf("%d\n", max);
    system("pause");
}