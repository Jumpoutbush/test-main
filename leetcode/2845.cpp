#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        long long res = 0;
        int prefix = 0;
        cnt[0] = 1;
        for(int i = 0; i < n; i ++){
            prefix += nums[i] % modulo == k;
            res += cnt[(prefix - k + modulo) % modulo];
            cnt[prefix % modulo] ++;    // [1, 3], [2, 1], [0, 1]
        }
        return res;
    }
};

int main()
{
    vector<int> v = {3, 1, 9, 6, 3};
    Solution sol;
    cout << sol.countInterestingSubarrays(v, 3, 0) << endl;
    system("pause");
    return 0;
}