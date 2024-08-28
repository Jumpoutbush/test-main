#include<bits/stdc++.h>
using namespace std;
int len[3] = {1, 2, 3};
int t, n, ans, res;
void dfs(int step, int cnt, int flag)
{
    if(step == n){
        res ++;
        ans = ans + cnt;
        return;
    }
    if(step > n) return;
    for(int i = 0; i < 3; i++)
    {
        if(flag == len[i]) continue;
        if(step + len[i] > n) continue;
        if(i == 0){
            dfs(step + len[i], cnt + 1, len[i]);
        }else{
            dfs(step + len[i], cnt, len[i]);
        }
    }
}
int main()
{
    std::vector<int> ve;
    cin >> t;
    while(t--)
    {
        ans = 0;
        res = 0;
        cin >> n;
        dfs(0, 0, 0);
        cout << res << endl << ans << endl;
    }
    return 0;
}
