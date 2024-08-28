#include<bits/stdc++.h>
using namespace std;
int N, P, r;
/*
N:总成员数
P:根supplier价格
r:分给每个distributor和retailer时增长百分比
Si是第i个成员的supplier的编号，root的supplier编号是-1
*/
int n, maxdepth = 0, maxnum = 0, temp, root;
vector<int> v[100];
void dfs(int index, int depth)
{
    if(v[index].size() == 0)//此时到根
    {
        if(maxdepth == depth)
            maxnum++;
        if(maxdepth < depth){
            maxdepth = depth;
            maxnum = 1;
        }
        return;
    }
    for(int i = 0; i < v[index].size(); i++)
        dfs(v[index][i], depth + 1);
}
int main()
{
    double p, r;
    scanf("%d %lf %lf", &n, &p, &r);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        if(temp == -1)
            root = i;
        else
            v[temp].push_back(i);
    }
    dfs(root, 0);
    printf("%.2f %d", p*pow(1 + r / 100, maxdepth), maxnum);
    system("pause");
    return 0;
}