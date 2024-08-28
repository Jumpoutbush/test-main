#include<iostream>
using namespace std;
const int MAXN = 100010;
const int MOD = 1000000007;
int leftNumP[MAXN]={0};
int main(){
    string str;
    cin>>str;
    /*for(int i=0;i<str.length();i++){
        if(str[i]=='P'){
            for(int j=i+1;j<str.length();j++){
                if(str[j]=='A'){
                    for(int k=j+1;k<str.length();k++){
                        if(str[k]=='T')
                            count++;
                    }
                }
            }
        }
    }//超时
    */
    //由A作为形成轴
    for(int i=0;i<str.length();i++){
        if(i>0){
            leftNumP[i]=leftNumP[i-1];
        }
        if(str[i]=='P'){
            leftNumP[i]++;
        }
    }
    int ans=0,rightNumT=0;
    for(int i=str.length()-1;i>=0;i--){
        if(str[i]=='T'){
            rightNumT++;
        }else if(str[i]=='A'){
            ans=(ans+leftNumP[i]*rightNumT) % MOD;
        }
    }
    cout<<ans;
    system("pause");
    return 0;
}