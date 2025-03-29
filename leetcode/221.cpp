#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxn = 0;
        int m = matrix.size();
        if(!m) return 0;
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
        }
        for(int i = 1; i < n; i++){
            dp[0][i] = matrix[0][i] == '1' ? 1 : 0;
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = matrix[i][j] == '1' ? min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]}) + 1 : 0;
                if(dp[i][j] > maxn){
                    maxn = dp[i][j];
                }
            }
        }
        return maxn * maxn;
    }
};

int main(){
    Solution s;
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout << s.maximalSquare(matrix) << endl;
    getchar();
    return 0;
}