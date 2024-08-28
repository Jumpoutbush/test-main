#include<iostream>
using namespace std;
int count=0;
const int maxn=11;
int n,P[maxn],hashTable[maxn]={false};
void generateP(int index){
	if(index==n+1){//递归边界，达到了一种符合排列的情况
		bool flag=true;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(i-j)==abs(P[i]-P[j])){//同一对角线P[i][j]=[j][i]
					flag=false;
				}
			}
		}
		if(flag) count++;
		return;
	}
	for(int x=1;x<=n;x++){//探查下一种排列
		if(hashTable[x]==false){
			P[index]=x;
			hashTable[x]=true;
			generateP(index+1);
			hashTable[x]=false;
		}
	}
}
int main(){
	n=8;
    generateP(1);
	cout<<count;
	system("pause");
    return 0;
}