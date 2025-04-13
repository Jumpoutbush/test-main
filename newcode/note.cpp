#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll> dp(n + 1, 0);
        for(int i = n - 1; i >= 0; --i){
            dp[i] = max(dp[i + 1], questions[i][0] + dp[min(n, i + questions[i][1] + 1)]);
        }
        return dp[0];
    }
};

int main()
{
    Solution s;
    vector<vector<int>> questions = {
        {1, 1},
        {2, 2},
        {3, 3},
        {4, 4},
        {5, 5}
    };
    ll ans = s.mostPoints(questions);
    cout << ans;
    getchar();
    return 0;
}