#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1000;

int tempL[maxn];
int tempR[maxn];


void merge(vector<int>& nums, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    for(int i = 0; i < n1; i++){
        tempL[i] = nums[left + i];
    }
    for(int i = 0; i < n2; i++){
        tempR[i] = nums[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
        if(tempL[i] <= tempR[j]){
            nums[k] = tempL[i];
            i++;
        }else{
            nums[k] = tempR[j];
            j++;
        }
        k ++;
    }
    while(i < n1){
        nums[k] = tempL[i];
        i++; k++;
    }
    while(j < n2){
        nums[k] = tempR[j];
        j++; k++;
    }
}
void mergeSort(vector<int>& nums, int left, int right){
    if(left < right){
        int mid = (right + left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }
}

int main(){
    vector<int> v = {1,0,8,9,7,3,2,5,6,4};
    mergeSort(v, 0, v.size() - 1);
    for(int i : v){
        cout << i << " ";
    }
    getchar(); 
    return 0;
}