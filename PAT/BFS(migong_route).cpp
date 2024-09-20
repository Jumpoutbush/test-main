/*
0 1 0 0 0
0 1 1 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 10;
const int maxstep = 100;
int matrix[maxn][maxn];
bool inq[maxn][maxn] = {false};

int X[4] = {0,0,1,-1};
int Y[4] = {1,-1,0,0};
int n,m;
struct node{
    int x,y,step;
    int a[maxstep];
    int b[maxstep];
}S,T,W,Node;
bool judge(int x, int y)
{
    if(x>=n||x<0||y>=m||y<0)
    {
        return false;
    }
    if(matrix[x][y] == 1 || inq[x][y] == true)
    {
        return false;
    }
    return true;
}
void BFS()
{
    queue<node> Q;
    Q.push(S);
    while(!Q.empty())
    {
        node top = Q.front();
        Q.pop();
        if(top.x == T.x && top.y == T.y)
        {
            for(int i=0;i <= top.step;i++)
                cout<<"("<<top.a[i]<<","<<top.b[i]<<")"<<endl;
            break;
        }
        for(int i =0; i< 4; i++)
        {
            Node = top;
            int newX = Node.x + X[i];
            int newY = Node.y + Y[i];
            if(judge(newX, newY))
            {
                Node.x = newX;
                Node.y = newY;
                Node.step = top.step+1;
                Node.a[Node.step] = Node.x;
                Node.b[Node.step] = Node.y;
                Q.push(Node);
                inq[newX][newY] = true;
            }
        }

    }
}
int main()
{
    scanf("%d%d", &n, &m);
    S.x = 0;
    S.y = 0;
    S.step = 0;
    T.x = n-1;
    T.y = m-1;
    inq[0][0] = true;
    for(int x = 0; x < n; x++)
    {
        for(int y = 0; y < m; y++)
        {
            scanf("%d", &matrix[x][y]);
        }
    }
    
    BFS();
    system("pause");
    return 0;
}