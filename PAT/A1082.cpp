#include<bits/stdc++.h>
using namespace std;
string dig[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
string wei[5] = {"Shi", "Bai", "Qian", "Wan", "Yi"};
int main(){
    string str;
    getline(cin, str);
    int len = str.length();
    string ans = "";
    if(str[0] == '-'){
        ans += "Fu";
        str = str.substr(1, len);
        len = len - 1;
    }//123456789

    int curlen = len;
    for(int i = 0; i < len; i++){
        ans += dig[str[i]];
    }
    cout << ans;
    return 0;
}