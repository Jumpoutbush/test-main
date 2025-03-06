#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int capacity, const std::vector<int>& weights, const std::vector<int>& values) 
{
    int n = weights.size();
    vector<int> dp(capacity + 1, 0);
    // 遍历物品，从下标0开始
    for(int i = 0; i < n; i++){
        for(int j = capacity; j >= weights[i]; j--){
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }
    return dp[capacity];
}
int main() {
    int capacity = 5;  // 背包容量
    std::vector<int> weights = {2, 1, 3};  // 物品重量
    std::vector<int> values = {4, 2, 3};   // 物品价值

    int result = knapsack(capacity, weights, values);
    std::cout << "max values is: " << result << std::endl;

    getchar();
    return 0;
}