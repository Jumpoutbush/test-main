#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <future>
using namespace std;

int knapsack(int capacity, const vector<int>& weights,
             const vector<int>& values)
{
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= capacity; j++){
            if(j < weights[i - 1]){
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
            }
        }
    }
    return dp[n][capacity];
}

int main() {
    int capacity = 5;  // 背包容量
    std::vector<int> weights = {2, 1, 3};  // 物品重量
    std::vector<int> values = {4, 2, 3};   // 物品价值

    future<int> futureResult = async(launch::async, knapsack, capacity, weights, values);
    thread thread1([=]{
        cout << "hello world" << endl;
    });
    // int result = knapsack(capacity, weights, values);
    int result = futureResult.get();
    thread1.join();
    std::cout << "Max value is: " << result << std::endl;

    getchar();
    return 0;
}