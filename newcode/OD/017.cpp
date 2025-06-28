#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> ans;
    void dfs(int cur, int n, int k){
        if(tmp.size() + (n - cur + 1) < k){
            return;
        }
        if(tmp.size() == k){
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(cur);
        dfs(cur + 1, n, k);
        tmp.pop_back();
        dfs(cur + 1, n, k);
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> ans = sol.combine(4, 2);
    for(auto vec : ans){
        for(int i : vec){
            cout << i << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}