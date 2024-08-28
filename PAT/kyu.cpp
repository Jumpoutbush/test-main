#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int num, count = 0;
    int a[10010] = {0};
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        a[num] ++;
    }
    for(int i = 0; i < 10010; i++)
    {
        if(a[i] >= k)
        {
            count = count + (a[i] - k + 1);
        }
    }
    cout << count;
    system("pause");
    return 0;
}