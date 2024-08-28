//找到节点数最多的层
/*
23 13
21 1 23
01 4 03 02 04 05
03 3 06 07 08
06 2 12 13
13 1 21
08 2 15 16
02 2 09 10
11 2 19 20
17 1 22
05 1 11
07 1 14
09 1 17
10 1 18

*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
vector<int> Node[maxn];
int hashTable[maxn] = {0};
void DFS(int index, int level)
{
    hashTable[level] ++;
    if(Node[index].size() != 0)
    {
        for(int i = 0; i < Node[index].size(); i++)
            DFS(Node[index][i], level + 1);
    }
}
int main()
{
    int n, m, parent, k, child;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &parent, &k);
        for(int j = 0; j < k; j++)
        {
            scanf("%d", &child);
            Node[parent].push_back(child);
        }
    }
    DFS(1, 1);
    int maxnum = -1, maxlevel = -1;
    for(int i = 0; i < maxn; i++)
    {
        if(hashTable[i] > maxnum){
            maxnum = hashTable[i];
            maxlevel = i;
        }
    }
    printf("%d %d", maxnum, maxlevel);
    system("pause");
    return 0;
}