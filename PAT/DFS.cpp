#include<iostream>
using namespace std;
const int maxn = 30;
int n,V,maxValue = 0;//物品件数、背包容量、最大价值maxValue
int w[maxn],c[maxn];//每件物品重量、每件物品价值
void DFS(int index, int sumW, int sumC){
    if(index == n){
        if(sumW <= V && sumC > maxValue){
            maxValue = sumC;
        }
        return ;
    }

    DFS(index+1,sumW,sumC);
    DFS(index+1,sumW+w[index],sumC+c[index]);
}
int main(){
    scanf("%d%d", &n, &V);
    for(int i=0;i<n;i++){
        scanf("%d", &w[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d", &c[i]);
    }
    DFS(0,0,0);
    printf("%d\n", maxValue);

    system("pause");
    return 0;
}