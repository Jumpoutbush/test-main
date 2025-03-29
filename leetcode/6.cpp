#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";
        if(numRows == 1) return s;
        array<array<char, 100>, 100> arr;
        for(auto & row : arr){
            for(auto & col : row){
                col = '|';
            }
        } 
        int m = 0, n = 0;
        int len = s.length();
        int i = 0;
        int flag = true;
        while(i < len) {
            while(m >= 0 && m < numRows && i < len){
                if(flag){
                    arr[m][n] = s[i];
                    m++;
                }else{
                    arr[m][n] = s[i];
                    m--;
                }
                ++i;
            }
            if(m == -1){
                m = m + 2;
            }else if(m == numRows){
                m = numRows - 2;
            }
            n++;
            flag = !flag;
        }
        for(int i = 0; i < 100; ++i){
            for(int j = 0; j < 100; ++j){
                if(arr[i][j] != '|'){
                    ans += arr[i][j];
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    cout << sol.convert("Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers.", 2) << endl;
    getchar();
    return 0;
}