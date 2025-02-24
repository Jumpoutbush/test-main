// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     int nums = 0;
//     void dfs(vector<vector<char>>& grid, int r, int c)
//     {
//         int row = grid.size();
//         int col = grid[0].size();

//         grid[r][c] = '0';
//         if(r + 1 < row && grid[r + 1][c] == '1') dfs(grid, r + 1, c);
//         if(r - 1 >= 0 && grid[r - 1][c] == '1') dfs(grid, r - 1, c);
//         if(c + 1 < col && grid[r][c + 1] == '1') dfs(grid, r, c + 1);
//         if(c - 1 >= 0 && grid[r][c - 1] == '1') dfs(grid, r, c - 1);
//     }
//     int numIslands(vector<vector<char>>& grid) {
//         int nr = grid.size();
//         if (!nr) return 0;
//         int nc = grid[0].size();
//         for(int i = 0; i < nr; i++)
//         {
//             for(int j = 0; j < nc; j++)
//             {
//                 if(grid[i][j] == '1'){
//                     nums ++;
//                     dfs(grid, i, j);
//                 }
//             }
//         }
//         return nums;
//     }
// };

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    struct node{
        int x, y;
        node() = default;
        node(int r, int c) : x(r), y(c){}
    };
    int X[4] = {0, 0, 1, -1};
    int Y[4] = {1, -1, 0, 0};
    queue<node> q;
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int row = grid.size();
        if(!row) return 0;
        int col = grid[0].size();
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == '1')
                {
                    ans ++;
                    grid[i][j] = '0';
                    node Node{i, j};
                    q.push(Node);
                    while(!q.empty())
                    {
                        auto top = q.front();
                        q.pop();
                        grid[i][j] = '0';
                        for(int c = 0; c < 4; c++)
                        {
                            int newX = top.x + X[c];
                            int newY = top.y + Y[c];
                            if(newX >= 0 && newX < row && newY >=0 && newY < col && grid[newX][newY] == '1')
                            {
                                node Node{newX, newY};
                                q.push(Node);
                                grid[newX][newY] = '0';
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<char> a{'1','1','1','1','0'};
    vector<char> b{'1','1','0','1','0'};
    vector<char> c{'1','1','0','0','0'};
    vector<char> d{'0','0','0','0','0'};
    vector<vector<char>> grid;
    grid.push_back(a);
    grid.push_back(b);
    grid.push_back(c);
    grid.push_back(d);
    cout << sol.numIslands(grid);
    getchar();
    return 0;
}