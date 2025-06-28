/*
 * @lc app=leetcode.cn id=2145 lang=cpp
 *
 * [2145] 统计隐藏数组数目
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long x = lower;
        long long  mini = x, maxn = x;
        long long cur = x;
        for(auto d : differences){
            cur += d;
            mini = min(mini, cur);
            maxn = max(maxn, cur);
        }
        return ((upper - maxn + 1) - (lower - mini)) > 0 ? (int)((upper - maxn + 1) - (lower - mini)) : 0;
    }
};
// @lc code=end
int main()
{
    Solution s;
    vector<int> differences = {4, -7, 2};
    /**
     * @example
     *    4 -7 2
     *  3 7  0 2
     *  4 8  1 3
     *  5 9  2 4
     *  6 10 3 5
     */
    int lower = 3, upper = 6;
    cout << s.numberOfArrays(differences, lower, upper) << endl;
    return 0;
}
