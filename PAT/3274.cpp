#include<bits/stdc++.h>
using namespace std;
const int maxn = 55;
int a[maxn] = {0};
int main()
{
    cout << (3 & 2) << endl;
    int n;
    while(scanf("%d", &n) != EOF)
    {
        bool flag = false, first = false;
        for(int i = 0 ; i < n; i++)
        {
            scanf("%d", &a[i]);
            if(a[i] > 1 && a[i] < 5)
            {
                flag = true;
                if(first == false)
                {
                    a[i] = 1;
                    a[i+1] = 1;
                    i ++;
                    n++;
                }
                first = true;
            }
        }
        if(flag == false)
        {
            cout << "Deep Dark Fantasy of ECNU" << endl;
        }else{
            for(int i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}