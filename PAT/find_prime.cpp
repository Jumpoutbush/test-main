#include<iostream>
using namespace std;
const int maxn=101;//表长
int prime[maxn],pNum=0;//prime数组存放所有素数，pNum为素数个数
bool p[maxn]={0};
void Find_Prime(){
    for(int i=2;i<maxn;i++){//不能写成i<=maxn
        if(p[i]==false){
            prime[pNum++]=i;
            for(int j=i+i;j<maxn;j+=i){
                //筛去i的所有倍数，循环条件不能写成j<=maxn
                p[j]=true;
            }
        }
    }
}
int main(){
    Find_Prime();
    for(int i=0;i<pNum;i++){
        cout<<prime[i]<<" ";
    }
    cout << endl;
    system("pause");
    return 0;
}