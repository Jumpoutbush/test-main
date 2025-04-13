#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool dfs(vector<int>& nums, int idx, int target, int cursum){
        if(cursum == target) return true;
        if(cursum > target || idx >= nums.size())   return false;

        if(dfs(nums, idx + 1, target, cursum + nums[idx]))  return true;

        return dfs(nums, idx + 1, target, cursum);
    }
    bool canPartition(vector<int>& nums) {
        int totalsum = 0;
        for(int i : nums){
            totalsum += i;
        }
        if(totalsum % 2 != 0) return false;
        int target = totalsum / 2;
        // 1, 1, 2, 2 | 1, 2 & 1, 2
        // 1 1 2
        return dfs(nums, 0, target, 0);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 5, 11, 5};
    cout << sol.canPartition(nums) << endl;
    getchar();
    return 0;
}