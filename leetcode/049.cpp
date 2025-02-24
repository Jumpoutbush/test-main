#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        if(strs.size() == 0)
            return ans;
        unordered_map<string, vector<string>> mp;
        for(auto & str : strs)
        {
            string tmp = str;
            sort(str.begin(), str.end());
            mp[str].push_back(tmp);
        }
        for (auto& t: mp) {
            ans.push_back(t.second);
        }
        return ans;
    }
};
int main()
{
    vector<string> strs;
    vector<vector<string> > ans;
    strs.push_back("eat");
    strs.push_back("tea");
    strs.push_back("tan");
    strs.push_back("ate");
    strs.push_back("nat");
    strs.push_back("bat");
    Solution slu;
    ans = slu.groupAnagrams(strs);
    for(auto & i : ans)
    {
        for(auto & j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}