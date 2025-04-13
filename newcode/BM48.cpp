#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<int> nums;
public:
    void Insert(int num) {
        nums.push_back(num);
        if(nums.size() < 2) return;
        int i = nums.size() - 2;
        int key = nums.back();  // 4
        // 2 3 5 4
        for(; i >= 0; i--){
            if(nums[i] > key){
                nums[i + 1] = nums[i];
            }else{break;}
        }
        i++;
        nums[i] = key;
    }

    double GetMedian() { 
        if(nums.size() % 2 == 0){
            int n1 = nums[nums.size() / 2 - 1];
            int n2 = nums[nums.size() / 2];
            return (double)(n1 + n2) / 2;
        }else{
            return (double)(nums[nums.size() / 2]);
        }
    }

};

int main(){
    Solution s;
    vector<int> v = {5,2,3,4,1,6,7,0,8};
    for(int i = 0; i < 9; i++){
        s.Insert(v[i]);
        printf("%.02f ", s.GetMedian());
    }
    getchar();
    return 0;
}

// [5,2,3,4,1,6,7,0,8]