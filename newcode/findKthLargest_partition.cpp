#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& nums, int start, int end){
    if(start >= end) return start;
    int randomIndex = start + rand() % (end - start + 1);
    swap(nums[randomIndex], nums[start]);
    int key = nums[start];
    int left = start, right = end;
    while(left < right){
        while(left < right && nums[right] < key) right --;
        while(left < right && nums[left] >= key) left ++;
        swap(nums[left], nums[right]);
    }
    if(nums[left] > nums[start]){
        swap(nums[left], nums[start]);
    }
    return left;
}

int randomSelect(vector<int>& nums, int left, int right, int k){
    if(left == right) return nums[left];
    int p = partition(nums, left, right);
    int m = p - left + 1;
    if(k == m) return nums[p];
    if(k < m){
        return randomSelect(nums, left, p - 1, k);
    }else{
        return randomSelect(nums, p + 1, right, k - m);
    }
}

int findKthLargest(vector<int>& nums, int k){
    int left = 0, right = nums.size() - 1;
    return randomSelect(nums, left, right, k);
}

int main()
{
    vector<int> v = {1, 2, 3, 2, 3, 4, 5, 1, 6, 7};
    cout << findKthLargest(v, 2) << endl;
    system("pause");
    return 0;
}