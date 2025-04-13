#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型
     */
    const static int maxn = 50005;
    int cnt = 0;
    array<int, maxn> tempL, tempR;
    int InversePairs(vector<int>& nums) {
        if((int)nums.size() < 2) return 0;
        mergesort(nums, 0, nums.size() - 1);
        return cnt;
    }

    void mergesort(vector<int>& nums, int left, int right){
        if(left < right){
            int mid = (left + right) / 2;
            mergesort(nums, left, mid);
            mergesort(nums, mid + 1, right);
            merge(nums, left, mid, right);
        }
    }

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
            if(tempL[i] <= tempL[j]){
                nums[k] = tempL[i];
                i++;
            }else{
                nums[k] = tempL[j];
                /*
                    nums = {5, 4, 2, 3, 1, 6}
                    tempL = {5, 4, 2}, n1 = 3
                            i=0
                    tempR = {3, 1, 6}
                */
                cnt += n1 - i;
                cnt %= 1000000007;
                j++;
            }
            k++;
        }
        while(i < n1){
            nums[k] = tempL[i];
            i ++; k++;
        }
        while(j < n2){
            nums[k] = tempR[j];
            j ++; k++;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    Solution s;
    s.InversePairs(nums);
    cout << s.cnt << endl;
    system("pause");
    return 0;
}