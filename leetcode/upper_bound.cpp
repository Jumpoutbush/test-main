#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto row = upper_bound(matrix.begin(), matrix.end(), target,
        [](const int b, const vector<int> &a){
            return b < a[0];
        });
        if (row == matrix.begin()) {
            return false;
        }
        -- row;
        return binary_search(row->begin(), row->end(), target);
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    cout<<s.searchMatrix(matrix,target)<<endl;
    getchar();
    return 0;
}