// 解密犯罪时间
#include <bits/stdc++.h>
using namespace std;

set<char> extartDigits(const string& time){
    set<char> digits;
    for(char c : time){
        if(isdigit(c)){
            digits.insert(c);
        }
    }
    return digits;
}

int timeDifference(int currentHour, int currentMinute, int newHour, int newMinute){
    int totalCurrentMinutes = currentHour * 60 + currentMinute;
    int totalNewMinutes = newHour * 60 + newMinute;
    return (totalNewMinutes - totalCurrentMinutes + 1440) % 1440;
}

string findNextClosestTime(const string& time){
    set<char> digits = extartDigits(time);

    int currentHour = stoi(time.substr(0, 2));
    int currentMinute = stoi(time.substr(3, 2));
    int minTimeDifference = INT_MAX;
    string result = time;

    for(char h1 : digits){
        for(char h2 : digits){
            for(char m1 : digits){
                for(char m2 : digits){
                    int newHour = (h1 - '0') * 10 + (h2 - '0');
                    int newMinute = (m1 - '0') * 10 + (m2 - '0');
                    if(newHour < 24 && newMinute < 60){
                        int diff = timeDifference(currentHour, currentMinute, newHour, newMinute);
                        if(diff > 0 && diff < minTimeDifference){
                            minTimeDifference = diff;
                            result = string(1, h1) + string(1, h2) + ":" + string(1, m1) + string(1, m2);
                        }
                    }
                }
            }
        }
    }
    return result;
}
int main()
{
    string time;
    cin >> time;
    string result = findNextClosestTime(time);
    cout << result << endl;
    system("pause");
    return 0;
}