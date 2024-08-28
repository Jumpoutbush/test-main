#include<bits/stdc++.h>
using namespace std;
const int maxn = 41;
int a[maxn][maxn] = {0};
int v[maxn][maxn] = {0};
int dp[maxn][maxn][maxn] = {0};
int main()
{
     int n, X;
     scanf("%d%d", &n, &X);
     for(int i = 0; i < n; i++)
     {
        int m;
        scanf("%d", &m);
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &v[i][j]);
        }
     }
     for(int i = 0; i <= n; i++)
     {
         for(int j = 0; j <= maxn; j++)
         {
             for(int x = a[i][j]; x <= X; x++)
             {
                 dp[i][j][x] = max(dp[i][j-1][x], dp[i][j-1][x-a[i][j]] + v[i][j]);
             }
         }
     }
     int max = -1;
     for(int i = 0; i <=n; i++)
     {
         for(int j = 0; j <= maxn; j++)
         {
             for(int x = 0; x <= X; x++)
             {
                 if(dp[i][j][x] > max);
                    max = dp[i][j][x];
             }
         }
     }
     cout << max;
     system("pause");
     return 0;
}