#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &nums[i]);
    }
    vector<int> freq(n + 1, 0);
    int left = 0;
    int valid = 0;
    ll ans = 0;
    for(int right = 0; right < n; right++){
        int x = nums[right];
        freq[x]++;
        if(freq[x] == k){
            valid ++;
        }
        while(valid > 0 && left <= right){
            ans += (n - right);
            int y = nums[left];
            if(freq[y] == k){
                valid --;
            }
            freq[y] --;
            left ++;
        }
    }
    cout << ans;
    system("pause");
    return 0;
}