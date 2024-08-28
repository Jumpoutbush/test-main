//给出一棵树，问每一层各有多少叶子节点
#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
int N, M, maxh = 1;
vector<int> G[maxn];
int leaf[maxn] = {0};
void dfs(int index, int h)
{
    maxh = max(h, maxh);
    if(G[index].size() == 0)
    {
        leaf[h]++;
        return;
    }
    for(int i = 0; i < G[index].size(); i++)
        dfs(G[index][i], h + 1);
}
int main()
{
    int parent, child, k;
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++)
    {
        scanf("%d%d", &parent, &k);
        for(int j = 0; j < k; j++)
        {
            scanf("%d", &child);
            G[parent].push_back(child);
        }
    }
    dfs(1, 1);
    printf("%d", leaf[1]);
    for(int i = 2; i <= maxh; i++)
        printf(" %d", leaf[i]);
    system("pause");
    return 0;
}