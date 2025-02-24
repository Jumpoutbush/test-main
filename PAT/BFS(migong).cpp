#include<iostream>
#include<queue>
using namespace std;
const int maxn = 30;
bool inq[maxn][maxn] = {false};
char matrix[maxn][maxn];
struct node{
    int x, y, step;
    node() = default;
    node(int r, int c) : x(r), y(c){}
}Node,S,T;
int n,m;
int X[] = {0,0,1,-1};
int Y[] = {1,-1,0,0};
bool judge(int x,int y){
    if(x >= n || x < 0 || y >= m || y < 0) return false;//越界
    if(matrix[x][y] == '*' || inq[x][y] == true) return false;//位置为0或已经入过队
    return true;
}
int BFS(){
    queue<node> Q;
    Q.push(S);
    while(!Q.empty()){
        node top = Q.front();
        Q.pop();
        if(top.x == T.x && top.y == T.y){
            return top.step;
        } 
        for(int i = 0;i < 4;i++){
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if(judge(newX,newY)){
                Node.x = newX,Node.y = newY;
                Node.step = top.step + 1;
                Q.push(Node);
                inq[newX][newY] = true;
            }
        }
    }
    return -1;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int x = 0; x < n; x++){
        getchar();//过滤掉每行后面的换行符
        for(int y = 0;y < m; y++){
            matrix[x][y] = getchar();
        }
        matrix[x][m+1] = '\0';
    }
    scanf("%d%d%d%d",&S.x,&S.y,&T.x,&T.y);
    S.step = 0;
    printf("%d\n",BFS());
    system("pause");
    return 0;
}


    // queue<node> q;
    // q.push(S);
    // while(!q.empty())
    // {
    //     node top = q.front();
    //     q.pop();
    //     if(top.x == T.x && top.y == T.y){
    //         return top.step;
    //     }
    //     for(int i = 0; i < 4; i++){
    //         int newX = top.x + X[i];
    //         int newY = top.y + Y[i];
    //         if(judge(newX, newY)){
    //             node Node(newX, newY);
    //             Node.step = top.step + 1;
    //             q.push(Node);
    //             inq[newX][newY] = true;
    //         }
    //     }
    // }
    // return -1;