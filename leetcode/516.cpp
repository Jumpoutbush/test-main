#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 1));
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
            if(i < n - 1){
                if(s[i] == s[i + 1]){
                    dp[i][i + 1] = 2;
                }
            }
        }
        for(int L = 3; L <= n; L++){
            for(int i = 0; i + L - 1 < n; i++){
                int j = i + L - 1;
                if(s[i] == s[j]){
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }else{
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]); // key
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main()
{
    Solution sol;
    cout << sol.longestPalindromeSubseq("beacabfhd") << endl;
    getchar();
    return 0;
}