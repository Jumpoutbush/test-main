#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // int lowerbound(vector<int>& nums, int target){
    //     int left = 0, right = nums.size();
    //     while(left < right){
    //         int mid = (left + right) / 2;
    //         if(nums[mid] < target){
    //             left = mid + 1;
    //         }else{
    //             right = mid;
    //         }
    //     }
    //     return left;
    // }

    // int upperbound(vector<int>& nums, int target){
    //     int left = 0, right = nums.size();
    //     while(left < right){
    //         int mid = (left + right) / 2;
    //         if(nums[mid] <= target){
    //             left = mid + 1;
    //         }else{
    //             right = mid;
    //         }
    //     }
    //     return left;
    // }

    vector<int> searchRange(vector<int>& nums, int target) {
        int leftidx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int rightidx = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        if(leftidx <= rightidx && rightidx < nums.size() && nums[leftidx] == target && nums[rightidx] == target){
            return vector<int>{leftidx, rightidx};
        }
        return vector<int>{-1, -1};
    }
};

int main()
{
    Solution S;
    vector<int> v{5, 7, 7, 8, 8, 10};
    vector<int> ans = S.searchRange(v, 8);
    for(int& i : ans){
        cout << i << " ";
    }
    getchar();
    return 0;
}