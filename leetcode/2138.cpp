#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> v;
        int n = s.length();
        string tmp;
        int i = 0;
        while(i < n){
            tmp.clear();
            int j = 0;
            while(j < k && i < n){
                tmp += s[i];
                i ++;
                j ++;
            }
            if(tmp.length() == k)
                v.push_back(tmp);
        }
        int dif = k - tmp.length();
        if(tmp.length() < k){
            for(int l = 0; l < dif; l++){
                tmp += fill;
            }
            v.push_back(tmp);
        }
        return v;
    }
};

int main()
{
    Solution sol;
    string s = "abcdefghij";
    int k = 3;
    char fill = 'x';
    vector<string> result = sol.divideString(s, k, fill);
    
    for (const string& str : result) {
        cout << str << endl;
    }
    system("pause");
    return 0;
}