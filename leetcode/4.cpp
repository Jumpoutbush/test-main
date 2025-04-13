#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> aftersort;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = (int)nums1.size(), n2 = (int)nums2.size();
        int i = 0, j = 0, k = 0;
        while(i < n1 && j < n2){
            if(nums1[i] < nums2[j]){
                aftersort[k] = nums1[i]; i++;
            }else{
                aftersort[k] = nums2[j]; j++;
            }
            k++;
        }
        while(i < n1){
            aftersort[k] = nums1[i];
            i++; k++;
        }
        while(j < n2){
            aftersort[k] = nums2[j];
            j++; k++;
        }
        if(aftersort.size() % 2 == 0){
            int l1 = aftersort.size() / 2 - 1, l2 = aftersort.size() / 2;
            int b1 = aftersort[l1], b2 = aftersort[l2];
            return (double)(b1 + b2) / 2;
        }else{
            return (double)aftersort[aftersort.size() / 2];
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> a = {1, 3};
    vector<int> b = {2};
    cout << s.findMedianSortedArrays(a, b) << endl;
    getchar();
    return 0;
}