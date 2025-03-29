#include <bits/stdc++.h>
using namespace std;

class Solution {
    const static int maxn = 105;
    int dp[maxn][maxn] = {0};
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int left = 0, len = 1;

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
            if (i < n - 1) {
                if (s[i] == s[i + 1]) {
                    dp[i][i + 1] = 1;
                    left = i;
                    len = 2;
                }
            }
        }
        for (int L = 3; L <= n; ++L) {
            for (int i = 0; i + L - 1 < n; i++) {
                int j = i + L - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                    dp[i][j] = 1;
                    left = i;
                    len = L;
                }
            }
        }
        string ans = s.substr(left, len);
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "aacabdkacaa";
    cout << sol.longestPalindrome(s) << endl;
    getchar();
    return 0;
}