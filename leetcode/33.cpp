#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& v, int target) {
        int pos = 0;
        for(int i = 1; i < v.size(); ++i){
            if(v[i] < v[i - 1]){
                pos = i;
            }
        }
        reverse(v.begin(), v.begin() + pos);
        reverse(v.begin() + pos, v.end());
        reverse(v.begin(), v.end());
        int left = 0, right = v.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(v[mid] == target){
                return mid;
            }else if(v[mid] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> v = {4,5,6,7,0,1,2};
    Solution s;
    cout << s.search(v, 0) << endl;
    getchar();
    return 0;
}