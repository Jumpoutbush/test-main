#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k1,k2;
    scanf("%d", &k1);
    int a1[k1+1];
    for(int i = 1; i <= k1; i++)
    {
        scanf("%d", &a1[i]);
    }
    scanf("%d", &k2);
    int a2[k2+1];
    for(int i = 1; i <= k2; i++)
    {
        scanf("%d", &a2[i]);
    }
    int p1 = 1, p2 = 1, p = 1, end = (k1 + k2 + 1) / 2;
    for(p1,p2; p1 <= k1 && p2 <= k2; )
    {
        if(a1[p1]<=a2[p2]){
            p1++;p++;
        }else if(a1[p1]>a2[p2]){
            p2++;p++;
        }
        if(p==end)
            break;
    }
    if(a1[p1] > a2[p2]){
        cout << a2[p2];
    }else if(a1[p1] <= a2[p2])
    {
        cout << a1[p1];
    }
    return 0;
    
    
}
/**
 * @brief 
#include <iostream>
const int maxn = 200005;
int n, m, a1[maxn], a2[maxn], cnt = 0, i, j, ans;
int main() {
	scanf("%d", &n);
	for(i = 1; i <= n; i++)	scanf("%d", &a1[i]);
	scanf("%d", &m);
	for(i = 1; i <= m; i++)	scanf("%d", &a2[i]);
	int target = (n + m + 1) / 2;
	i = 1, j = 1;
	while(i <= n && j <= m) {
		ans = a1[i] <= a2[j] ? a1[i++] : a2[j++];
		if(++cnt == target)	break;
	}
	if(i <= n && cnt < target)	
		ans = a1[i + target - cnt - 1];
	else if(j <= m && cnt < target)	
		ans = a2[j + target - cnt - 1];
	printf("%d", ans);
	return 0;
}
 * 
 */