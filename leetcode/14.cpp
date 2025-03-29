#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        int ans = 0;
        int n = strs[0].length();

        for(int i = 0; i < n; ++i){
            string first = strs[0];
            prefix += first[i];
            for(string & str : strs){
                string substr = str.substr(0, i + 1);
                if(substr != prefix){
                    prefix = prefix.substr(0, prefix.length() - 1);
                    return prefix;
                }
            }
        }

        return prefix;
    }
};

int main(){
    Solution sol;
    vector<string> strs = {"flower","flow","flight"};
    cout << sol.longestCommonPrefix(strs) << endl;
    getchar();
    return 0;
}