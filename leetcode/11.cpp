#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len, hai, vol;
        int ans = -1;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            len = right - left;
            hai = min(height[right], height[left]);
            vol = len * hai;
            ans = max(vol, ans);
            if(height[left] > height[right]){
                right --;
            }else{
                left ++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution slo;
    vector<int> nums;
    for(int i = 0; i < 9; i++){
        int z;
        scanf("%d", &z);
        nums.push_back(z);
    }
    cout << slo.maxArea(nums);
    system("pause");
    return 0;
}