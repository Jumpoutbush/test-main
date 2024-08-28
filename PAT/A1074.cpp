#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
struct Node{
    int address, data, next;
    int order;
}node[maxn];
bool cmp(Node a, Node b)
{
    return a.order < b.order;
}
int main()
{
    for(int i = 0; i < maxn; i++)
    {
        node[i].order = maxn;
    }
    int begin, n, k, address;
    scanf("%d%d%d", &begin, &n, &k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &address);
        scanf("%d%d", &node[address].data, &node[address].next);
        node[address].address = address;
    }
    int p = begin, count = 0;
    while(p != -1)
    {
        node[p].order = count++;
        p = node[p].next;
    }
    sort(node, node + maxn, cmp);
    n = count;
    return 0;
}