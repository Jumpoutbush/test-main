// tlv解析
#include <bits/stdc++.h>
using namespace std;
/*
    @brief 输入一行string，tag+len+value
           输入要匹配的个数n
           输入n行要匹配的tag
    @brief
           输出n行 长度+偏移量
*/
int hextodec(string str){
    if(str.length() > 2) return -1;
    int ans = 0;
    for(int i = 0; i < 2; i++){
        int tmp = 0;
        if(isdigit(str[i])){
            tmp += (str[i] - '0');
        }else if(isalpha(str[i])){
            tmp = tmp + 10 + (str[i] - 'A');
        }
        tmp *= pow(16, 1-i);
        ans += tmp;
    }
    return ans;
}
// 0F04ABABAB
unordered_map<int, vector<int>> deal(string& str){
    unordered_map<int, vector<int>> buffer;
    str += " ";
    int l = 0, r = 0;
    while(r < str.length() - 1){
        r ++;
        string substr = str.substr(l, r - l + 1);
        int tag = hextodec(substr);
        l = r + 1;
        r += 2;
        substr = str.substr(l, r - l + 1);
        int len = hextodec(substr);
        if(str.length() > r + len * 2 + 1){
            r += len * 2 + 1; l = r;
            buffer[tag] = vector<int>{len, (r - len * 2) / 2};
        }else{
            break;
        }
    }
    return buffer;
}

int main()
{
    string package;
    cin >> package;
    unordered_map<int, vector<int>> buffer = deal(package);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int tag;
        cin >> tag;
        if(buffer.find(tag) != buffer.end()){
            cout << buffer[tag][0] << " " << buffer[tag][1] << endl;
        }else{
            cout << "0 0" << endl;
        }
    }
    system("pause");
    return 0;
}