#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
const int INF = 0xfffffff;
int N, num = 0;
double P, r, ans = INF;
struct node{
    double data;
    vector<int> child;
}Node[maxn];
bool notRoot[maxn] = {false};
int findRoot()
{
    for(int i = 0; i <= N; i++)
    {
        if(notRoot[i] == false)
            return i;
    }
}
void dfs(int index, int depth)
{
    if(Node[index].child.size() == 0)
    {
        double price = P * pow(1 + r, depth);
        Node[index].data = price;
        if(price < ans){
            ans = price;
            num = 1;
        }else if(price == ans)
        {
            num ++;
        }
        return;
    }
    for(int i = 0; i < Node[index].child.size(); i++)
        dfs(Node[index].child[i], depth + 1);
    
}
int main()
{
    int k, child;
    cin >> N >> P >> r;
    r /= 100;
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &k);
        if(k == 0)
            continue;
        else{
            for(int j = 0; j < k; j++)
            {
                scanf("%d", &child);
                Node[i].child.push_back(child);
                notRoot[child] = true;
            }
        }
    }
    int root = findRoot();
    dfs(root, 0);
    printf("%.4f %d\n", ans, num);
    system("pause");
    return 0;
}