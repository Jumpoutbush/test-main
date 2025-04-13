#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param num int整型vector 
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> ans;
    vector<int> tmp;
    vector<bool> used;
    void dfs(vector<vector<int>>& ans, vector<int>& num, int n, int idx){
        if(idx == n){
            ans.push_back(tmp);
            return;
        }
        for(int i = 0; i < n; i++){
            if(!used[i]){
                tmp.push_back(num[i]);
                used[i] = true;
                dfs(ans, num, n, idx + 1);
                used[i] = false;
                tmp.pop_back();
            }
        }
    }
    vector<vector<int> > permute(vector<int>& num) {
        // write code here
        int n = num.size();
        if(n == 0) return ans;
        if(n == 1){
            ans.push_back(num);
            return ans;
        }
        sort(num.begin(), num.end());   // 1, 2, 3
        used.resize(n, false);
        dfs(ans, num, n, 0);
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> num = {1, 2, 3};
    for(auto& v : s.permute(num)){
        for(auto& e : v){
            cout << e << " ";
        }
        cout << endl;
    }
    getchar(); 
    return 0;
}