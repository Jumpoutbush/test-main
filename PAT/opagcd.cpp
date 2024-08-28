#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b)
{
    if(b == 0) return a;
    else return gcd(b, a % b);
}
int main()
{
    int T;
    scanf("%d", &T);
    while( T > 0)
    {
        T--;
        long long x, y, k;
        cin >> x >> y >> k;
        long long res = -1;
        for(long long i = 0; i <= k; i++)
        {
            long long j = k - i;
            long long p = x + i;
            long long q = y + j;
            long long cur = gcd(p, q);
            if(cur > res)
                res = cur;
        }
        cout << res << endl;
    }
    return 0;
}