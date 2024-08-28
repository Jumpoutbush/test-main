#include<bits/stdc++.h>
using namespace std;
int every[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
    string s;
    cin >> s;
    bool flag = true;
    string month = s.substr(5, 2);
    string day = s.substr(8, 2);
    int mon = stoi(month);
    int da = stoi(day);
    int early = 0;
    if(mon > 12 || mon < 1) flag = false;
    int i = 0;
    for(i = 0; i < mon; i++)
    {
        early += every[i];
    }
    if(da > every[i] || da < 1)  flag = false;
    early += da;
    flag == false ? cout << -1 : cout << early; 
    system("pause");
    return 0;
}
