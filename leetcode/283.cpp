#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero = 0, noze = 0;
        while(zero < nums.size() - 1 && noze < nums.size() - 1)
        {
            while(nums[zero] != 0 && zero < nums.size() - 1){
                zero ++;
            }
            while(nums[noze] == 0 && noze < nums.size() - 1){
                noze ++;
            }
            if(zero < noze){
                swap(nums[zero], nums[noze]);       
            } else {
                noze ++;
            } 
        }

    }
};

int main()
{
    Solution slo;
    vector<int> nums;
    for(int i = 0; i < 7; i++){
        int z;
        scanf("%d", &z);
        nums.push_back(z);
    }
    slo.moveZeroes(nums);
    for(auto & i : nums)
    {
        cout << i << " ";
    }
    system("pause");
    return 0;
}