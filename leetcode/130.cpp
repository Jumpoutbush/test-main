#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;

    vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<char>>& board, int x, int y){
        if(x < 0 || x >= n || y < 0 || y >= m || board[x][y] != 'O'){
            return;
        }
        board[x][y] = 'A';
        for(auto& d : dirs){
            int newx = x + d[0], newy = y + d[1];
            dfs(board, newx, newy);
        }
    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        if(n == 0) return;
        m = board[0].size();
        for(int i = 0; i < n; i++){
            dfs(board, i, 0);
            dfs(board, i, m - 1);
        }
        for(int i = 1; i < m - 1; i++){
            dfs(board, 0, i);
            dfs(board, n - 1, i);
        }
        for(int i = 0; i < n; i++){
            for(int j  = 0; j < m; j++){
                if(board[i][j] == 'A'){
                    board[i][j] == 'O';
                }else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<char>> board{{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    s.solve(board);
    for(auto& row : board){  
        for(auto& c : row){
            cout << c << ' ';
        }
        cout << endl;
    }
    getchar();
    return 0;
}