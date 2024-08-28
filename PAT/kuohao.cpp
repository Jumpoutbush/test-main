#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int res = 0;
    if(s.length() == 0)
        return res;
    vector<int> dp(s.length(), 0);
    for(int i = 1; i < s.length(); i++)
    {
        if(s[i] == ')')
        {
            if(s[i - 1] == '(')
                dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
            else if(i - dp[i - 1] > 0 && s[i-dp[i-1]-1] == '(')
                dp[i] = (i - dp[i-1] > 1 ? dp[i-dp[i-1]-2]: 0) + dp[i-1] + 2;
        }
        res = max(res, dp[i]);
    }
    cout << res << endl;
    system("pause");
    return 0;
}
