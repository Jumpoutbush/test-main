
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
string S;
int dp[maxn][maxn];     //dp[i][j]表示S[i] 至 S[j]表示的子串是否回文, 0/1
int main()
{
    getline(cin, S);
    int len = S.length();                                   
    int ans = 1;
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < len; i++){
        dp[i][i] = 1;
        if(i < len - 1){
            if(S[i] == S[i + 1]){//由于判断子串长度需要-2,初始化边界1和2长度的子串
                dp[i][i + 1] = 1;
                ans = 2;
            }
        }
    }
    for(int L = 3; L < len; L++)//1,2已在上面判断过
    {
        for(int i = 0; L + i - 1 < len; i++)
        {
            int j = L + i - 1;      //子串右端点
            if(S[i] == S[j] && dp[i + 1][j - 1] == 1){
                dp[i][j] = 1;
                ans = L;
            }
        }
    }

    printf("%d", ans);
    system("pause");
    return 0;
}