#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    std::vector<int> findAnagrams(string s, string p) {
        vector<int> v;
        if(s.length() < p.length())
            return v;
        vector<string> words;
        do{
            words.push_back(p);
        }while(next_permutation(p.begin(), p.end()));
        for(int i = 0; i < s.length() - p.length() + 1; i++)
        {
           string substr = s.substr(i, p.length());
           for(auto& x : words){
                if(substr == x){
                    v.push_back(i);
                    break;
                }
           }
        }
        return v;
    }
};

int main()
{
    Solution slu;
    vector<int> v = slu.findAnagrams("bcabcabcabca", "abc");
    for(auto & i : v){
        cout << i << " ";
    }
    getchar();
    return 0;
}