#include<bits/stdc++.h>
using namespace std;
const int maxn = 205;
int a[maxn] = {0};
int main()
{
    int n;
    int total = 0;
    scanf("%d", &n);
    int num;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        a[i] = num;
        total += num;
    }
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += a[j];
            if(sum == total / 2){
                count ++;
                break;
            }else if(sum > total / 2){
                break;
            }
        }
    }
    cout << count;
    system("pause");
    return 0;
}