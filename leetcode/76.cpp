#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<char, int> ori, cnt;

    bool check(){
        for(auto& p : ori){
            if(cnt[p.first] < p.second){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        for(auto& c : t){
            ++ori[c];
        }

        int l = 1, r = -1;
        int len = INT_MAX, ans = -1;

        while(r < int(s.size())){
            if(ori.find(s[++r]) != ori.end()){
                ++cnt[s[r]];
            }
            while(check() && l <= r){
                if(r - l + 1 < len){
                    len = r - l + 1;
                    ans = l;
                }
                if(ori.find(s[l]) != ori.end()){
                    --cnt[s[l]];
                }
                ++l;
            }
        }
        return ans == -1 ? string() : s.substr(ans, len);
    }
};


int main(){
    Solution sol;
    cout << sol.minWindow("ADOBECODEBANC", "ABC") << endl;
    getchar();
    return 0;
}