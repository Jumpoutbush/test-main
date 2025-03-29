#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = 0;
        int ans = -1;
        bool found = false;
        while(start < n)
        {
            for(int i = start; i < gas.size(); ++i){
                if(gas[i % n] >= cost[i % n]){
                    start = i;
                    break;
                }
            }
            int sum_gas = 0, sum_cost = 0;
            for(int i = start; i <= start - 1 + n; ++i){
                sum_gas += gas[i % n];
                sum_cost += cost[i % n];
                if(sum_gas >= sum_cost){
                    if(i == start - 1 + n) found = true;
                    continue;
                }else{
                    ++ start;
                    break;
                }
            }
            if(found){
                ans = start;
                break;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> gas = {5, 1, 2, 3, 4};
    vector<int> cost = {4, 4, 1, 5, 1};
    cout << s.canCompleteCircuit(gas, cost) << endl;  
    getchar(); 
    return 0;
}