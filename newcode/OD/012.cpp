// 代码编辑器
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    string s;
    cin >> k >> s;
    int pointer = 0;
    int len = s.length();
    for(int i = 0; i < k; i++){
        string command;
        getline(cin, command);
        if(command.find("FORWARD")){
            int val = stoi(command.substr(8));
            pointer = min(pointer + val, len);
        }else if(command.find("BACKWARD")){
            int val = stoi(command.substr(9));
            pointer = max(pointer - val, 0);
        }else if(command.find("SEARCH-FORWARD")){
            string word = command.substr(15);
            auto pos = command.find(word, pointer);
            if(pos != string::npos){
                pointer = pos;
            }
        }else if(command.find("SEARCH-BACKWORD")){
            string word = command.substr(16);
            auto pos = command.rfind(word, pointer);
            if(pos != string::npos){
                pointer = pos;
            }
        }else if(command.find("INSERT")){

        }else if(command.find("REPLACE")){

        }else if(command.find("DELETE")){

        }
    }
}