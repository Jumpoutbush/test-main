// 最大相连男生数
#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans = 0;

int main()
{
    scanf("%d%d", &n, &m);
    vector<vector<char>> grids(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        string line;
        cin >> line;
        for(int j = 0; j < m; j ++){
            grids[i][j] = line[j * 2];
        }
    }
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};
    int maxCount = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grids[i][j] == 'M'){
                for(auto& d : dirs){
                    int rI = i - d[0];
                    int rJ = j - d[1];
                    if(rI >= 0 && rI < n && rJ >= 0 && rJ < m){
                        continue;
                    }
                    int newI = i + d[0];
                    int newJ = j + d[1];
                    int curCount = 1;
                    while(newI >= 0 && newI < n && newJ >= 0 && newJ < m && grids[newI][newJ] == 'M'){
                        curCount ++;
                        newI += d[0];
                        newJ += d[1];
                    }
                    maxCount = max(maxCount, curCount);
                }
            }
        }
    }
    cout << maxCount << endl;
    return 0;
}