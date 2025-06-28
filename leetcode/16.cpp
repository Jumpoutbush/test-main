#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int cur = 0, closer = INT_MAX, ans;
        while(cur < nums.size() - 2){
            if(nums[cur] > target) break;
            int left = cur + 1, right = nums.size() - 1;
            while(left < right){
                int sum = nums[cur] + nums[left] + nums[right];
                int dis = abs(target - sum);
                if(dis == 0){
                    return sum;
                }
                if(dis < closer){
                    ans = sum;
                    closer = dis;
                }
                //while(left < right && nums[left + 1] == nums[left]) left ++;
                //while(left < right && nums[right - 1] == nums[right]) right --;
                if(sum > target){
                    right--;
                }else{
                    left ++;
                }
            }
            cur ++;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-4,2,2,3,3,3};
    cout << s.threeSumClosest(nums, 0) << endl;
    system("pause");
    return 0;
}