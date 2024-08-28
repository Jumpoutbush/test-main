#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
struct node{
    double data;//与1090不同的是，除父节点以外需要保存data值
    vector<int> child;
}Node[maxn];
int n;
double p, r, ans = 0;
void dfs(int index, int depth)
{
    if(Node[index].child.size() == 0)
    {
        ans += Node[index].data * pow(1 + r, depth);
        return;
    }
    for(int i = 0; i < Node[index].child.size(); i++)
        dfs(Node[index].child[i], depth + 1);
}
int main()
{
    int k, child;
    scanf("%d%lf%lf", &n, &p, &r);
    r /= 100;
    for(int i = 0 ; i < n; i++)
    {
        scanf("%d", &k);
        if(k==0){
            scanf("%lf", &Node[i].data);
        }else{
            for(int j = 0; j < k; j++)
            {
                scanf("%d", &child);
                Node[i].child.push_back(child);
            }
        }
    }
    dfs(0, 0);
    printf("%.1f\n", p * ans);
    system("pause");
    return 0;
}