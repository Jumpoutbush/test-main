#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int m, n;
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx,
             vector<vector<bool>> visited) {
        if (idx == word.length() - 1)
            return true;
        visited[i][j] = true;

        for (auto& d : dirs) {
            int x = i + d[0], y = j + d[1];
            if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] &&
                board[x][y] == word[idx + 1]) {
                if (dfs(board, word, x, y, idx + 1, visited)) {
                    return true;
                }
            }
        }
        visited[i][j] = false;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        if (!m)
            return false;
        n = board[0].size();
        unordered_map<char, int> cnt;
        for (auto& row : board) {
            for (char c : row) {
                cnt[c]++;
            }
        }
        unordered_map<char, int> word_cnt;
        for (char c : word) {
            if (++word_cnt[c] > cnt[c])
                return false;
        }

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0, visited)) {   // 因为word下标从0开始
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    cout << s.exist(board, word) << endl;
    getchar();
    return 0;
}