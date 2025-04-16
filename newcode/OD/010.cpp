// 最大矩阵和
#include <bits/stdc++.h>
using namespace std;

int kadane(const vector<int>& nums){
    int maxEndingHere = 0;
    int maxSoFar = INT_MIN;
    for(int num : nums){
        maxEndingHere = max(num, maxEndingHere + num);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}

int maxSubmatrixSum(const vector<vector<int>>& nums){
    int n = nums.size();
    int m = nums[0].size();
    int maxSum = INT_MIN;
    for(int left = 0; left < m; left++){
        vector<int> temp(n, 0);
        for(int right = left; right < m; right++){
            for(int i = 0; i < n; i++){
                temp[i] += nums[i][right];
            }
            int currentSum = kadane(temp);
            maxSum = max(maxSum, currentSum);
        }
    }
    return maxSum;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> nums(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &nums[i][j]);
        }
    }
    
}