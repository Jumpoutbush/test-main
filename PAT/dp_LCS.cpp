#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 100;
char A[N],B[N];
int dp[N][N];
//sadstory adminsorry
//字符串A的i号位和字符串B的j号位之前的LCS长度
//dp[4][5]表示sads与admin的LCS长度

int main(){
    int n;
    gets(A+1);  //数组下标从1开始读取
    gets(B+1);
    int lenA = strlen(A + 1);
    int lenB = strlen(B + 1);
    //A[i] == B[j] 如 A[4] = B[6] = 's', dp[4][6] = dp[3][5]
    //A[i] != B[j] LCS无法延长, 继承dp[i-1][j] 与 dp[i][j-1]的最大值
    //例如 A[3] != B[3], 继承max(LCS(sa, adm), LCS(sad, ad))
    for(int i = 0; i <= lenA; i++)
    {
        dp[i][0] = 0;
    }
    for(int i = 0; i <= lenB; i++)
    {
        dp[0][i] = 0;
    }
    for(int i = 1; i <= lenA; i++)
    {
        for(int j =1; j <= lenB; j++)
        {
            if(A[i] == B[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    printf("%d\n", dp[lenA][lenB]);
    system("pause");
    return 0;
}
