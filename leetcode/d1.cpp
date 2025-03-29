#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getKthMagicNumber(int k) {
        if(k == 1) return 1;
        vector<int> dp(k + 1);
        dp[1] = 1;
        int p3 = 1, p5= 1, p7 = 1;
        for(int i = 2; i <= k; i++){
            int num3 = dp[p3] * 3, num5 = dp[p5] * 5, num7 = dp[p7] * 7;
            dp[i] = min({num3, num5, num7});
            if(dp[i] == num3){
                p3++;
            }
            if(dp[i] == num5){
                p5++;
            }
            if(dp[i] == num7){
                p7++;
            }
        }
        return dp[k];
    }
};

int main()
{
    Solution s;
    cout << s.getKthMagicNumber(7) << endl;
    return 0;
}