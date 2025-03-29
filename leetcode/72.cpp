#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for(int i = 0; i < len1; ++i){
            dp[i + 1][0] = i + 1;
        }
        for(int i = 0; i < len2; ++i){
            dp[0][i + 1] = i + 1;
        }
        for(int i = 1; i <= len1; ++i){
            for(int j = 1; j <= len2; ++j){
                dp[i + 1][j + 1] = word1[i] == word2[j] ? dp[i][j]
                        : min({dp[i][j+1], dp[i+1][j], dp[i][j]}) + 1;  //插入、删除、替换
            }
        }
        return dp[len1][len2];
    }
};

int main()
{
    Solution s;
    cout << s.minDistance("horse", "ros") << endl;
    getchar();
    return 0;
}