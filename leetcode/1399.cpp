#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> ump;
        int ans = -1, cnt = 0;
        for(int i = 1; i <= n; i++){
            string s = to_string(i);
            int tmp = 0;
            for(int j = 0; j < s.length(); j++){
                tmp += s[j] - '0';
            }
            ump[tmp] ++;
        }
        for(auto& it : ump){
            if(it.second > ans){
                cnt = 0;
                ans = it.second;
                cnt ++;
            }else if(it.second == ans){
                cnt ++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.countLargestGroup(13) << endl;
    system("pause");
    return 0;
}