#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
class Solution {
private:
    bool vis[10] = {0};
    vector<set<int>> ans;
    vector<int> tmp;
    void dfs(vector<set<int>>& ans, vector<int>& tmp, bool vis[], int sum, int k, int n){
        if(sum == n){
            if(tmp.size() == k){
                set<int> inner;
                for(auto i : tmp){
                    inner.insert(i);
                }
                if(find(ans.begin(), ans.end(), inner) == ans.end())
                    ans.emplace_back(inner);
                return;
            }else if(tmp.size() < k){
                return;
            }
        }

        for(int i = 1; i < 10; i++){
            if(!vis[i]){
                vis[i] = 1;
                if(tmp.size() < k && sum + i <= n){
                    tmp.push_back(i);

                    dfs(ans, tmp, vis, sum + i, k, n);
                    tmp.pop_back();
                }
                vis[i] = 0;
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(ans, tmp, vis, 0, k, n);
        vector<vector<int>> res;
        for(auto vec : ans){
            vector<int> inner;
            for(auto i : vec){
                inner.push_back(i);
            }
            res.push_back(inner);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    auto ans = sol.combinationSum3(9, 45);
    for(auto vec : ans){
        for(auto i : vec){
            cout << i << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}