#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int total = accumulate(nums.begin(), nums.end(), 0);
    int maxnum = INT_MIN;
    int prefix = 0, back = 0;
    for(int idx = 0; idx < n; idx++){
        prefix += nums[idx];
        back = total - prefix;
        maxnum = max(maxnum, (prefix * back) % MOD);
    }
    cout << maxnum << endl;
    system("pause");
    return 0;
}