#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        if(matrix.empty()) return v;
        // 横
        int l = 0;
        int r = matrix[0].size() - 1;
        // 纵
        int t = 0;
        int b = matrix.size() - 1;
        while(true){
            for(int i = l; i <= r; ++i) v.push_back(matrix[t][i]);
            if(++t > b) break;
            for(int i = t; i <= b; ++i) v.push_back(matrix[i][r]);
            if(--r < l) break;
            for(int i = r; i >= l; --i) v.push_back(matrix[b][i]);
            if(--b < t) break;
            for(int i = b; i >= t; --i) v.push_back(matrix[i][t]);
            if(++l > r) break;
        }
        return v;
    }
};
int main()
{
    vector<vector<int>> v{
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    Solution sol;
    vector<int> res = sol.spiralOrder(v);
    for(int i : res){
        cout << i << " ";
    }
    getchar();
}