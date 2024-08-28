//N个整数中选K个数，使得这K个数之和恰好等于一个给定的整数X，如果有多种方案，选择它们中元素平方和最大的一个
#include<iostream>
#include<vector>
using namespace std;
const int maxn = 30;
int n,k,x,maxSumSqu = -1,A[maxn]={0};
vector<int> temp,ans;
void dfs(int index, int nowK, int sum, int sumSqu){//sum为数字和，sumSqu为平方和，需找出最大值赋予maxSumSqu
    if(nowK == k && sum == x){
        if(sumSqu > maxSumSqu){
            maxSumSqu = sumSqu;
            ans = temp;
        }
        return ;
    }
    if(index == n || nowK > k || sum > x) return ;
    temp.push_back(A[index]);
    dfs(index+1, nowK+1, sum+A[index], sumSqu + A[index]*A[index]);//把下一种状态的情况写入下一层dfs中
    temp.pop_back();//不选index号数
    dfs(index+1, nowK, sum, sumSqu);
}
int main(){
    cin>>n>>k>>x;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    dfs(0,0,0,0);
    cout<<maxSumSqu;
    system("pause");
    return 0;
}