#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> v;
    vector<int> tmp;
    void dfs(vector<vector<int>>& v, int start, int n, vector<int>& tmp,
                int cnt, int k)
    {
        if(cnt == k){
            v.push_back(tmp);
            return;
        }
        for(int i = start; i <= n; i++){
            tmp.push_back(i);
            dfs(v, i + 1, n, tmp, cnt + 1, k);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(v, 1, n, tmp, 0, k);
        return v;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v = s.combine(4, 2);
    for(auto i : v){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}