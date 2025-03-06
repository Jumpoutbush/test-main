#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& nums, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for(int i = 0; i < n1; i++){
        L[i] = nums[left + i];
    }
    for(int j= 0; j < n2; j++){
        R[j] = nums[mid + 1 + j];
    }
    
}