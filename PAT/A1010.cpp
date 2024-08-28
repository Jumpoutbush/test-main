#include<iostream>
#include<cctype>
#include<cmath>
#include<algorithm>
using namespace std;
long long convert(string n, long long radix){
    long long sum = 0;
    int index=0,temp = 0;
    for(auto it = n.rbegin();it!=n.rend();it++){//反向迭代器，从低位向高位加
        temp = isdigit(*it)?*it-'0':*it-'a'+10;
        sum += temp * pow(radix,index++);
    }
    return sum;
}
long long find_radix(string n, long long num){
    char it = *max_element(n.begin(), n.end());//最大数字，不加*表示最大值位置
    long long low = (isdigit(it)?it-'0':it-'a'+10) + 1;//方便输出Impossible？
    long long high = max(num,low);
    while(low<=high){
        long long mid = (low+high)/2;
        long long t = convert(n,mid);
        if(t==num){
            return mid;
        }else if(t<0||t>num){
            high = mid -1;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}
int main(){
    string n1,n2;
    long long tag=0,radix=0,result_radix;
    cin>>n1>>n2>>tag>>radix;
    result_radix = tag == 1?find_radix(n2,convert(n1,radix)):find_radix(n1,convert(n2,radix));
    if(result_radix!=-1){
        printf("%lld",result_radix);
    }else{
        printf("Impossible");
    }
    system("pause");
    return 0;
}