#include<iostream>
#include<string>
using namespace std;
int main(){
    int sign;
    string a,b;
    string doc = ".";
    cin>>sign>>a>>b;   
    bool flag = true;
    int doca = a.find(doc),docb = b.find(doc);
    string asub = a.substr(0,doca);
    string bsub = b.substr(0,docb);
    if(asub.length()!=bsub.length()){flag = false;}
    for(int i=0;i<sign&&i<asub.length()&&i<bsub.length();i++){
        if(asub[i]!=bsub[i]){
            flag = false;
        }
    }
    int powa=asub.length(),powb=bsub.length();//a、b的阶码
    string showa = a.substr(0,sign);
    string showb = b.substr(0,sign);

    if(atoi(a.c_str())==0) {powa = 0;showa = a;}
    if(atoi(b.c_str())==0) {powb = 0;showb = b;}
    if(atoi(a.c_str())==0&&atoi(b.c_str())==0&&a.length()<b.length()){
        showa = showb;
    }
    if(flag){
        cout<<"YES ";
        if(atoi(a.c_str())==0&&atoi(b.c_str())==0){
            cout<<showa<<"*10^"<<powa;
        }else{
            cout<<"0."<<showa<<"*10^"<<powa;
        }
    }else{
        cout<<"NO ";
        cout<<"0."<<showa<<"*10^"<<powa<<" "<<"0."<<showb<<"*10^"<<powb;
    }
    system("pause");
    return 0;
}