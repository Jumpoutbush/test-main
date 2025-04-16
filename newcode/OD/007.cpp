// 符合要求的元组个数 100
#include <bits/stdc++.h>
using namespace std;

int k, target;
vector<int> nums;
vector<int> tmp;
unordered_map<string, int> record;
string vectostring(vector<int>& tmp){
    string s = "";
    for(int i : tmp){
        s += to_string(i);
    }
    return s;
}
void dfs(vector<int>& nums, vector<int>& tmp, int idx, int total, int k, int target){
    if(idx == k && total == target){
        record[vectostring(tmp)]++;
        return;
    }
    for(int i = idx; i < nums.size(); i++){
        total += nums[i];
        if(total <= target && idx + 1 <= k){
            tmp.push_back(nums[i]);
            dfs(nums, tmp, idx + 1, total, k, target);
            tmp.pop_back();
        }else{
            break;
        }
        total -= nums[i];
    }
}

int main(){
    string s;
    getline(cin, s);
    istringstream iss(s);
    int num;
    while(iss >> num){
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    // -2 -1 3 4 5
    cin >> k >> target;
    dfs(nums, tmp, 0, 0, k, target);
    cout << record.size();
    system("pause");
    return 0;
}