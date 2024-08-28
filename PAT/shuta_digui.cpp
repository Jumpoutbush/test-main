#include<iostream>
using namespace std;
const int maxn = 1000;
int result = 0;
int cur_max = -1;
int arr[maxn][maxn];
int n;
void search(int depth, int pos, int n){//行值、列值、深度
    if(pos>depth) return;//递归终止条件1：当前行不超过深度
    result += arr[depth][pos];//路径大小值加上本层搜索结点
    if(depth == n){//递归终止条件2：如果已经达到最后一层
        if(result > cur_max)//更新最大路径值
            cur_max = result;
        result -= arr[depth][pos];//否则在返回时路径值复原到上一层
        return;
    }
    search(depth+1,pos,n);
    search(depth+1,pos+1,n);
    result -= arr[depth][pos];
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        cin>>arr[i][j];
    }
    search(1,1,n);//从数塔的第一个元素开始搜索，即搜索位置为第1层的第1个元素 
    cout<<cur_max;
    system("pause");
    return 0;
}