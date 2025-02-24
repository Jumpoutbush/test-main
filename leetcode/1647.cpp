#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arr[26];
    int minDeletions(string s) {
        int ans = 0;
        unordered_set<int> set;
        for(char c : s){
            arr[c - 'a']++;
        }
        for(int x : arr){
            while(set.count(x)){
                ans ++;
                x--;
            }
            if(x){
                set.insert(x);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string str;
    getline(cin, str);
    cout << sol.minDeletions(str);
    getchar();
    return 0;
}