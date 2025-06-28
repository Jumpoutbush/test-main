// a ^ b
#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
vector<int> tmp;
bool valid(int a, int b, int c){
    if(a + b > c && a + c > b && b + c > a && a - b < c && a - c < b && b - c < a){
        return true;
    }
    return false;
}

void dfs(vector<int>& nums, vector<int>& tmp, int cur, int n){
    if(tmp.size() == 2){
        if(valid(tmp[0], tmp[1], tmp[0] ^ tmp[1])){
            cnt++;
            return;
        }else{
            return;
        }
    }
    tmp.push_back(nums[cur]);
    if(cur < n)
        dfs(nums, tmp, cur + 1, n);
    tmp.pop_back();
    if(cur < n)
        dfs(nums, tmp, cur + 1, n);
}
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    dfs(nums, tmp, 0, n);
    cout << cnt << endl;
    system("pause");
    return 0;
}