#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int randPartition(vector<int>& a, int l, int r){
        if(l >= r) return l;
        int randomIndex = l + rand() % (r - l + 1);
        swap(a[l], a[randomIndex]);
        int key = a[l];
        int left = l, right = r;
        while(left < right){
            while(left < right && a[right] >= key) right--;
            while(left < right && a[left] <= key) left++;
            swap(a[left], a[right]);
        }
        if(a[left] < key){
            swap(a[left], a[l]);
        }
        return left;
    }
    int randselect(vector<int>& a, int l, int r, int K){
        if(l == r) return a[l];
        int p = randPartition(a, l, r);
        int M = p - l + 1; // a[p]是第M大
        if(M == K) return a[p];
        if(M < K){
            return randselect(a, p + 1, r, K - M);  //M个数的后半部分第K-M个即第K个
        }else{
            return randselect(a, l, p - 1, K); //M个数的前半部分第K个
        }
    }
    int findKth(vector<int>& a, int n, int K) {
        return randselect(a, 0, n-1, K);
    }
};

int main()
{
    Solution s;
    vector<int> a = {15, 31, 53, 76, 943, 223, 421, 624, 845, 10};
    int K = 7;
    cout << s.findKth(a, a.size(), K) << endl;
    getchar();
    return 0;
}