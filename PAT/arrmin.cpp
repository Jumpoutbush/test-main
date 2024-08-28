#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> v;
    int num;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        v.push_back(num);
        sum += num;
    }
    int res;
    if(sum <= m || v.size() == 0)    
        res = -1;
    else{
        for(int i = 0; i < m / (n/2); i++)
        {
            int total = 0;
            for(int j = 0; j < n; j++)
            {
                total += min(v[j], i);
            }
            if(total > m)
            {
                res = i - 1;
                break;
            }
        }
    }
    cout << res;
    system("pause");
    return 0;
}