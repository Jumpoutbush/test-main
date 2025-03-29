#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto & it : nums){
            st.emplace(it);
        }
        int longest = -1;
        for(auto & it : st){
            if(!st.count(it - 1)){
                int curlen = 1;
                int cur = it;
                while(st.count(cur + 1)){
                    curlen ++;
                    cur++;
                }
                longest = max(longest, curlen);
            }
        }
        return longest;
    }
};

int main(){
    Solution s;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << s.longestConsecutive(nums) << endl;
    return 0;
}