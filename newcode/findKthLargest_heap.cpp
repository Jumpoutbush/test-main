#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void heapify(vector<int>& nums, int n, int i){
        int largest = i;
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        if(left < n && nums[left] > nums[largest]){
            largest = left;
        }
        if(right < n && nums[right] > nums[largest]){
            largest = right;
        }
        if(largest != i){
            swap(nums[largest], nums[i]);
            heapify(nums, n, largest);
        }
    }
    void findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = n / 2 - 1; i >= 0; i--){
            heapify(nums, n, i);
        }
        for(int i = n - 1, cnt = 0; i > 0 && cnt < k; i--, cnt++){
            swap(nums[i], nums[0]);
            heapify(nums, i, 0);
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums{4, 5, 7, 9, 2, 3, 8, 1};
    sol.findKthLargest(nums, 8);
    for(int i : nums){
        cout << i << " ";
    }
    getchar();
    return 0;
}