#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,a[N],f[N],x,k;
int c[N];
map<int,int>p[N];
int main(){
    cin>>n>>k;
    long long ans=0;
    for(int i=1;i<=n;i++){
        f[i]=f[i-1];
        cin>>x;
        c[x]++;
        p[x][c[x]]=i;
        if(c[x]>=k)f[i]=max(f[i],p[x][c[x]-k+1]);
        if(f[i])ans+=f[i];
    }
    cout<<ans;
    return 0;
}
