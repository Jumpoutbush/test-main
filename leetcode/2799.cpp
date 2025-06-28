#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> ust;
        for(int num : nums){
            ust.insert(num);
        }
        int n = nums.size();
        unordered_set<int> tmp;
        int left = 0, ans = 0;
        while(left < n){
            int right = left;
            tmp.clear();
            while(tmp.size() < ust.size() && right < n){
                tmp.insert(nums[right]);
                right ++;
            }
            if(tmp.size() == ust.size()){
                ans += (n - right + 1);
            }
            left ++;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1,3,1,2,2};
    cout << sol.countCompleteSubarrays(nums) << endl;
    system("pause");
    return 0;
}