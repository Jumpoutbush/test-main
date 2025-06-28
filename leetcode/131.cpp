#include <bits/stdc++.h>
using namespace std;
class Solution {
    int n;
    vector<vector<int>> f;
    vector<vector<string>> ans;
    vector<string> tmp;
public:
    void dfs(string& s, int i){
        if(i == n){
            ans.push_back(tmp);
            return;
        }
        for(int j = i; j < n; j++){
            if(f[i][j] == 1){
                tmp.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.length();
        f.resize(n, vector<int>(n, true));
        for(int i = n - 1; i >= 0; i--){    // 先计算i + 1行 j - 1列，i最大串最短
            for(int j = i + 1; j < n; j++){
                f[i][j] = f[i + 1][j - 1] && s[i] == s[j];
            }
        }
        dfs(s, 0);
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<string>> ret = sol.partition("aab");
    for(auto& v : ret){
        for(auto& s : v){
            cout << s << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}