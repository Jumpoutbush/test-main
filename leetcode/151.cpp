#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word = "";
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == ' '){
                words.insert(words.begin(), word);
                word = "";
            }else if(i == s.length() - 1){
                word += s[i];
                words.insert(words.begin(), word);
            }else{
                word += s[i];
            }
        }
        string ans = "";
        for(int i = 0; i < words.size() - 1; ++i){
            ans = ans + words[i] + ' ';
        }
        ans += words[words.size() - 1];
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "  hello world  ";
    cout << sol.reverseWords(s) << endl;
    getchar();
    return 0;
}