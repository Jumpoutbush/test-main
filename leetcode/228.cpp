#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> vec;
        if(!nums.size()){
            return vec;
        }else if(nums.size() == 1){
            vec.push_back(to_string(nums[0]));
            return vec;
        }
        int left = 0, right = 1;
        int dis = 1;
        while(right < nums.size()){
            if(nums[right] == nums[left] + dis){
                right++;
                dis++;
            }else{
                string str;
                str = str + to_string(nums[left]) +
                    (dis == 1 ? "" : "->" + to_string(nums[right - 1]));
                vec.push_back(str);
                left = right;
                right++;
                dis = 1;
            }
        }
        vec.push_back(to_string(nums[left]) +(dis == 1 ? "" : "->" + to_string(nums[right - 1])));
        return vec;
    }
};

int main(){
    Solution sol;
    vector<int> v{0};
    vector<string> ans = sol.summaryRanges(v);
    for(auto& i : ans){
        cout << i << endl;
    }
    system("pause");
    return 0;
}