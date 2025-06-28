#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> memo(target + 1, -1);
        function<int(int)> dfs = [&](int i){
            if(i == 0){
                return 1;
            }
            int& res = memo[i];
            if(res != -1){
                return res;
            }
            res = 0;
            for(int x : nums){
                if(x <= i){
                    res += dfs(i - x);
                }
            }
            return res;
        };
        return dfs(target);
    }
};

int main()
{
    vector<int> v = {1, 2, 3};
    Solution s;
    cout << s.combinationSum4(v, 4) << endl;
    getchar();
    return 0;
}