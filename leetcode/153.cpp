#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // 345678912  123456789
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while(left < right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] >= nums[left] && nums[mid] > nums[right]){  // 中间大 671
                left = mid + 1;
            }else if(nums[mid] >= nums[left] && nums[mid] < nums[right]) // 升序, 降序不存在123
            {
                right = mid;
            }else if(nums[mid] <= nums[left] && nums[mid] < nums[right]) // 中间小712
            {
                left = mid;
            } 
        }
        return nums[left];
    }
};

int main()
{
    vector<int> nums = {5, 1, 2, 3, 4};
    Solution sol;
    cout << sol.findMin(nums) << endl;
    system("pause");
    return 0;
}