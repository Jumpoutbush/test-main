#include <iostream>
#include <vector>
using namespace std;
int upperbound(vector<int> &v, int key) {
    int l = 0, r = v.size() - 1;
    while(l < r){
        int mid = (l + r) / 2;
        if(v[mid] <= key){
            l = mid + 1;
        }else{
            r = mid;
        }
    }
    return l;
}

int main()
{
    vector<int> v{1,2,5,6,8,8,8,10};
    cout << upperbound(v, 8);
    getchar();
    return 0;
}
