#include<iostream>
using namespace std;
int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main(){
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF){
        printf("%d\n",gcd(m,n));
    }
    system("pause");
    return 0;
}