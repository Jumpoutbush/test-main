#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> tmp;
unordered_map<string, int> record;
int cnt = INT_MAX;
string vectostring(unordered_map<int, int>& tmp){
    string ans = "";
    for(auto& i : tmp){
        ans += to_string(i.first);
    }
    return ans;
}
bool dfs(vector<vector<int>>& nums, unordered_map<int, int>& tmp, int idx, int x){
    for(int j = 0; j < nums[idx].size(); j++){
        if(nums[idx][j] == 1){
            tmp[j] ++;
        }
    }
    x++;
    if(record.find(vectostring(tmp)) != record.end()) return true;
    record[vectostring(tmp)] = min(record[vectostring(tmp)], x);

    if(tmp.size() == nums[0].size()){
        cnt = min(cnt, x);
        return true;
    }
    for(int i = idx; i < nums.size(); i++){
        if(dfs(nums, tmp, i + 1, x)){
            continue;
        } 
    }
    for(int j = 0; j < nums[idx].size(); j++){
        if(nums[idx][j] == 1){
            tmp[j] --;
            if(tmp[j] == 0){
                tmp.erase(j);
            }
        }
    }
}
int main()
{
    int i, j;
    cin >> i >> j;
    vector<vector<int>> nums(i, vector<int>(j));
    for(int n = 0; n < i; n++){
        for(int m = 0; m < j; m++){
            cin >> nums[n][m];
        }
    }
    dfs(nums, tmp, 0, 0);
    cnt = cnt > i ? -1 : cnt;
    cout << cnt;
    system("pause");
    return 0;
}
