// 最佳出牌方法 200
#include <bits/stdc++.h>
using namespace std;

vector<int> cnt(14, 0);
unordered_map<string, int> record;
enum type{
    dpair = 2,
    tpair = 2,
    shunzi = 2,
    boom = 3
};
string gethand(vector<int>& cnt){
    // 反向记录cnt中剩余的牌
    string rcd;
    for(int i : cnt){
        rcd += to_string(i);
    }
    return rcd;
}
int dfs(vector<int>& cnt)
{
    bool hascnt = false;
    for(auto i : cnt){
        if(i > 0){
            hascnt = true;
            break;
        }
    }
    if(!hascnt){
        return 0;
    }
    string key = gethand(cnt);
    if(record.find(key) != record.end()){
        return record[key];
    }
    int maxscore = 0;
    // 炸弹
    for(int i = 1; i <= 13; i++){
        if(cnt[i] >= 4){
            cnt[i] -= 4;
            maxscore = max(maxscore, i * 4 * boom + dfs(cnt));
            cnt[i] += 4;
        }
    }
    // 顺子
    for(int i = 1; i <= 10; i++){
        if(cnt[i] > 0 && cnt[i + 1] > 0 && cnt[i + 2] > 0 && cnt[i + 3] > 0 && cnt[i + 4] > 0){
            for(int j = i; j <= i + 4; j++){
                cnt[j] --;
            }
            int sum = i * 5 + 10;
            maxscore = max(maxscore, sum * shunzi + dfs(cnt));
            for(int j = i; j <= i + 4; j++){
                cnt[j] ++;
            }
        }
    }
    // 三张
    for(int i = 1; i <= 13; i++){
        if(cnt[i] >= 3){
            cnt[i] -= 3;
            maxscore = max(maxscore, i * 3 * tpair + dfs(cnt));
            cnt[i] += 3;
        }
    }
    // 对子
    for(int i = 1; i <= 13; i++){
        if(cnt[i] >= 2){
            cnt[i] -= 2;
            maxscore = max(maxscore, i * 2 * dpair + dfs(cnt));
            cnt[i] += 2;
        }
    }
    //单张
    for(int i = 1; i <= 13; i++){
        if(cnt[i] >= 1){
            cnt[i] -= 1;
            maxscore = max(maxscore, i + dfs(cnt));
            cnt[i] += 1;
        }
    }
    record[key] = maxscore;
    return maxscore;
}
int main()
{
    string ware = "_1234567890JQK";
    string s;
    getline(cin, s);
    for(char c : s){
        int pos = ware.find(c);
        cnt[pos]++;
    }
    int ans = dfs(cnt);
    cout << ans;
    system("pause");
    return 0;
}