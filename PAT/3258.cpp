#include<bits/stdc++.h>
using namespace std;
int main()
{
    int p, q;
    scanf("%d%d", &p, &q);
    int a, b, c, d;
    b = sqrt(q);
    d = sqrt(q);
    for(c = 0; c <= sqrt(p); c++)
    {
        a = p - c * c;
        float fa = sqrt(a);
        int ia = sqrt(a);
        if(fa == ia)
        { 
            a = sqrt(a);
            break;
        }
    }
    printf("%d %d %d %d", a, b, c, d);
    system("pause");
    return 0;
}