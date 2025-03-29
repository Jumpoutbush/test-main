#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minMutation(string startGene, string endGene, vector<string>& bank) {
            unordered_set<string> cnt;
            unordered_set<string> visited;
            char keys[4] = {'A', 'C', 'G', 'T'};
            for(auto& i : bank){
                cnt.emplace(i);
            }
            if(startGene == endGene) return 0;
            if(!cnt.count(endGene)) return -1;
    
            queue<string> qu;
            qu.emplace(startGene);
            int step = 1;
            while(!qu.empty()){
                int sz = qu.size();
                for(int i = 0; i < sz; i++){
                    string cur = qu.front();
                    qu.pop();
                    for(int j = 0; j < 8; j++){
                        for(int k = 0; k < 4; k++){
                            if(cur[j] != keys[k]){
                                string next = cur;
                                next[j] = keys[k];
                                if(!visited.count(next) && cnt.count(next)){
                                    if(next == endGene)
                                        return step;
                                    qu.emplace(next);
                                    visited.emplace(next);
                                }
                            }
                        }
                    }
                }
                ++ step;
            }
            return -1;
        }
    };

int main()
{
    Solution s;
    string startGene = "AACCGGTT", endGene = "AAACGGTA";
    vector<string> bank = {"AACCGATT","AACCGATA","AAACGATA","AAACGGTA"};
    cout << s.minMutation(startGene, endGene, bank) << endl;
    getchar();
    return 0;
}