#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    int k;
    scanf("%d", &k);
    int i = 0;
    int mir[100010] = {0}; 
    for(int i = 1 ;i <= s.length(); i++)
    {
        mir[i] = s[i-1] - 'a';
    }
    sort(mir, mir + s.length()+1);
    int n = mir[k];
    char c = 'a' + n;
    int maxn = mir[s.length()];
    char maxc = 'a' + maxn;
    if(k > s.length())
    {
        for(i = 0; i < s.length(); i++)
        {
            if(s[i] == maxc)
                break;
        }
    }else{
        for(i = 0; i < s.length(); i++)
        {
            if(s[i] == c)
                break;
        }
    }
    cout << i;
    return 0;

}