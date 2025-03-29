#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // return length
        int lmin = INT_MAX;
        int l = 0, r = 0, rcd = 0;
        while(r < nums.size()){
            rcd += nums[r];
            if(rcd < target){
                ++ r;
            }else{
                lmin = min(lmin, l - r + 1);
                ++ r; l = r;
            }
        }
        return lmin;
    }
};

int main()
{
    vector<int> v{1, 4, 4};
    Solution sol;
    cout << sol.minSubArrayLen(4, v);
    getchar();
    return 0;
}