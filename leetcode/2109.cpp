#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        sort(spaces.begin(), spaces.end(), [](int a, int b){
            return a < b;
        });
        int n = spaces.size();
        int left = 0;
        vector<string> ans;
        for(int i = 0; i < n; i++){
            int len = i == 0 ? spaces[i] : spaces[i] - spaces[i - 1];
            string substr = s.substr(left, len);
            substr = substr + " ";
            ans.push_back(substr);
            left = spaces[i];
        }
        string substr = s.substr(left, s.size() - left);
        ans.push_back(substr);
        string ansstr = "";
        for(int i = 0; i < ans.size(); i++){
            ansstr += ans[i];
        }
        return ansstr;
    }
};

int main()
{
    Solution sol;
    string s = "LeetcodeHelpsMeLearn";
    vector<int> spaces = {8,13,15};
    cout << sol.addSpaces(s, spaces) << endl;
    getchar();
    return 0;
}