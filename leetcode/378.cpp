#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<vector<int>>& matrix, int mid, int k, int n){
        int i = n - 1, j = 0;   // 左下
        int num = 0;
        while(i >= 0 && j < n){
            if(matrix[i][j] <= mid){
                num += i + 1;
                j++;
            }else{
                i--;
            }
        }
        return num >= k;
    }
    
    // 计算中间值 mid，并使用 check 函数判断 mid 是否是一个可行解
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];
        while(left < right){
            int mid = left + (right - left) / 2;
            if(check(matrix, mid, k, n)){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
    cout << s.kthSmallest(matrix, 8) << endl;
    getchar();
    return 0;
}