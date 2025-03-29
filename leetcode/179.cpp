#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    static bool cmp(const int a, const int b){
        string sa = to_string(a);
        string sb = to_string(b);
        return sa + sb > sb + sa;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string ans = "";
        for(auto& num : nums){
            string s = to_string(num);
            ans += s;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3,30,34,5,9};
    cout << sol.largestNumber(nums) << endl;
    getchar();
    return 0;
}