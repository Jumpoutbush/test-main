// 需要广播的服务器数量
#include <bits/stdc++.h>
using namespace std;

int broadcast(vector<vector<int>>& map){
    int ans = 0, n = map.size();
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(map[i][i] == 1){
            ans ++;
            q.push(i);
            while(!q.empty()){
                int cur = q.front();
                map[cur][cur] = 0;
                q.pop();
                for(int j = 0; j < n; j++){
                    if(map[i][j] == 1){
                        q.push(j);
                        map[i][j] = 0; map[j][i] = 0;
                    }
                }
            }
        }
    }
    return ans;
}
int main()
{
    string str;
    int i = 0;
    vector<int> firstline;
    getline(cin, str);
    istringstream iss(str);
    int num;
    while(iss >> num){
        firstline.push_back(num);
    }
    int n = firstline.size();

    vector<vector<int>> map(n, vector<int>(n));
    map[0] = firstline;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }
    int ans = broadcast(map);
    cout << ans << endl;
    system("pause");
    return 0;
}