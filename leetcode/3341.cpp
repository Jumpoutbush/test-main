#include <assert.h>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int inf = 0x3f3f3f3f;
    const vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> dist(n, vector<int>(m, inf));
        queue<pair<int, int>> q;
        dist[0][0] = 0;
        q.emplace(0, 0);
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int x = cur.first, y = cur.second;

            for(int i = 0; i < 4; i++){
                int nx = x + dirs[i][0], ny = y + dirs[i][1];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] > max(dist[x][y], moveTime[nx][ny]) + 1){
                    dist[nx][ny] = max(dist[x][y], moveTime[nx][ny]) + 1;   // dist[x][y]表示前一个点可达，moveTime表示当前时间更优
                    q.emplace(nx, ny);
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};
int main()
{
   
    Solution sol;
    // Test case 1: Normal case with different move times
    vector<vector<int>> moveTime1 = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << sol.minTimeToReach(moveTime1) << endl;

    // Test case 2: All move times are the same
    vector<vector<int>> moveTime2 = {{2, 2, 2}, {2, 2, 2}, {2, 2, 2}};
    cout << sol.minTimeToReach(moveTime2) << endl;

    // Test case 3: Single row matrix
    vector<vector<int>> moveTime3 = {{1, 2, 3, 4, 5}};
    cout << sol.minTimeToReach(moveTime3) << endl;

    // Test case 4: Single column matrix
    vector<vector<int>> moveTime4 = {{1}, {2}, {3}, {4}, {5}};
    cout << sol.minTimeToReach(moveTime4) << endl;

    // Test case 5: 1x1 matrix
    vector<vector<int>> moveTime5 = {{1}};
    cout << sol.minTimeToReach(moveTime5) << endl;

    // Test case 6: Matrix with only two cells
    vector<vector<int>> moveTime6 = {{1, 2}};
    cout << sol.minTimeToReach(moveTime6) << endl;

    // Test case 7: Matrix with large values
    vector<vector<int>> moveTime7 = {{1000, 2000}, {3000, 4000}};
    cout << sol.minTimeToReach(moveTime7) << endl;

    // Test case 8: Matrix with zeros
    vector<vector<int>> moveTime8 = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    cout << sol.minTimeToReach(moveTime8) << endl;

    system("pause");
    return 0;
}