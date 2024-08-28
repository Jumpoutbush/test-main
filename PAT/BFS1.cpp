#include<iostream>
#include<queue>
using namespace std;
const int maxn = 100;
struct node{
	int x,y;
}Node;
int n,m;
int matrix[maxn][maxn];//01矩阵
bool inq[maxn][maxn] = {false};//记录位置(x,y)是否已入过队
int X[] = {0,0,1,-1};
int Y[] = {1,-1,0,0};
bool judge(int x,int y){
    if(x >= n || x < 0 || y >= m || y < 0) return false;//越界
    if(matrix[x][y] == 0 || inq[x][y] == true) return false;//位置为0或已经入过队
    return true;
}
void BFS(int x,int y){
    queue<node> Q;
    Node.x = x,Node.y = y;
    Q.push(Node);
    inq[x][y] = true;
    while(!Q.empty()){
        node top = Q.front();
        Q.pop();
        for(int i = 0;i < 4;i++){//循环四次，得到四个相邻位置
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if(judge(newX,newY)){//判断周边四个点是否需要入队
                Node.x = newX,Node.y = newY;
                Q.push(Node);
                inq[newX][newY] = true;
            }
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for(int x = 0;x < n;x++){
        for(int y = 0;y < m;y++){
            scanf("%d", &matrix[x][y]);
        }
    }
    int ans = 0;
    for(int x= 0;x < n;x++){
        for(int y = 0;y < m;y++){
            if(matrix[x][y] == 1 && inq[x][y] == false){
                ans++;
                BFS(x,y);
            }
        }
    }
    printf("%d\n",ans);
    system("pause");
    return 0;
}