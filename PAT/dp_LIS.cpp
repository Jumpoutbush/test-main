#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int A[N], dp[N];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &A[i]);
    }
    int ans = -1;
    for(int i = 1; i <= n; i++){
        dp[i] = 1;  //border
        for(int j = 1; j < i; j++){
            if(A[i] >= A[j]  && (dp[j] + 1 > dp[i])){//compare with the formers
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}