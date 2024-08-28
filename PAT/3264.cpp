# include <bits/stdc++.h>
using namespace std;
stack<int>s;
int main()
{
    int n, a, b, sum = 0;
    scanf("%d",&n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d%d",&a,&b);
        if(b == 0)
        {
            while(!s.empty() && s.top() < a) ++sum, s.pop();
            if(!s.empty()) ++sum;
        }
        else
            s.push(a);
    }
    printf("%d\n",n-sum);
    return 0;
}