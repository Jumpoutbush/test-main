#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long cnt = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            auto left = lower_bound(nums.begin(), nums.begin() + i, lower - nums[i]);
            auto right = upper_bound(nums.begin(), nums.begin() + i, upper - nums[i]);
            cnt += (right - left);
        }
        return cnt;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0,1,7,4,4,5};
    int lower = 3, upper = 6;
    cout << sol.countFairPairs(nums, lower, upper) << endl;
    system("pause");
    return 0;
}