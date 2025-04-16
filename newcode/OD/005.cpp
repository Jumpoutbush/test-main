// 组合出合法最小数
#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b){
    return (a + b) < (b + a);
}
string removezeros(string& s){
    int i = 0, n = s.size();
    while(i < n && s[i] == '0')
        i++;
    return s.substr(i);  
}
int main()
{
    string s;
    getline(cin, s);
    vector<string> nums;
    istringstream iss(s);
    string num;
    while(iss >> num){
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end(), cmp);
    if(!nums.empty() && nums[0][0] == '0'){
        for(int i = 1; i < nums.size(); i++){
            if(nums[i][0] != '0'){
                swap(nums[0], nums[i]);
                break;
            }
        }
    }
    string res;
    for(auto s : nums){
        res += s;
    }

    if(res.size() > 1 && res[0] == '0'){
        res = removezeros(res);
    }
    cout << (res.empty() ? "0" : res) << endl;
    system("pause");
    return 0;
}