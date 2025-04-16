// 跳格子游戏
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> nums(n, 0);
    vector<vector<int>> rely(n, vector<int>());
    vector<int> indeg(n, 0);
    for(int i = 0; i < m; i++){
        int prev, next;
        cin >> prev >> next;
        rely[prev].push_back(next);
        indeg[next]++;
    }
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(indeg[i] == 0 && nums[i] == 0){
            q.push(i);
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                nums[cur] = 1;
                for(auto value : rely[cur]){
                    indeg[value] --;
                    if(indeg[value] == 0)
                        q.push(value);
                }
            }
        }
    }
    bool success = true;
    for(const int& i : nums){
        if(i == 0){
            success = false;
        }
    }
    if(success){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }
    system("pause");
    return 0;
}