#include <bits/stdc++.h>
using namespace std;
class Solution {
    void backtrack(vector<string>& ans, string& cur, int open, int close, int n){
        if(cur.length() == n * 2){
            ans.push_back(cur);
            return;
        }
        if(open < n){
            cur.push_back('(');
            backtrack(ans, cur, open + 1, close, n);
            cur.pop_back();
        } 
        if(close < open){
            cur.push_back(')');
            backtrack(ans, cur, open, close + 1, n);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n);
        return result;
    }
};

int main()
{
    Solution s;
    vector<string> ans = s.generateParenthesis(3);
    for(auto& str : ans){        
        cout << str << endl;
    }  
    getchar();
    return 0;
}