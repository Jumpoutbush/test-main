#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n, m, S;
struct node{
    int weight;
    vector<int> child;
}Node[maxn];
vector<int> path;
vector<vector<int>> ans;
void DFS(int index, vector<int> path, int sum)
{
    if(sum > S) return;
    if(sum == S)
    {
        if(Node[index].child.size() != 0) return;
        ans.push_back(path);
        return;
    }
    for(int i = 0; i < Node[index].child.size(); i++)
    {
        int child = Node[index].child[i];
        path.push_back(Node[child].weight);
        DFS(child, path, sum + Node[child].weight);
        path.pop_back();
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    cin >> S;
    for(int i = 0; i < n; i++)
        scanf("%d", &Node[i].weight);
    int id, k, child;
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &id, &k);
        for(int j = 0;j < k; j++)
        {
            scanf("%d", &child);
            Node[id].child.push_back(child);
        }
    }
    path.push_back(Node[0].weight);
    DFS(0, path, Node[0].weight);
    sort(ans.begin(), ans.end(), greater<vector<int>>());
    for(int i = 0; i < ans.size(); i++)
    {
        printf("%d", ans[i][0]);
        for(int j = 1; j < ans[i].size(); j++)
        {
            printf(" %d", ans[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}