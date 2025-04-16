// 链表的中间节点
#include <bits/stdc++.h>
using namespace std;


int main()
{
    int headv, n;
    cin >> headv >> n;
    unordered_map<int, vector<int>> list;   // key = address， 
                                        // vector[0] = value, vec[1] = next
    for(int i = 0; i < n; i++){
        int add, val, next;
        cin >> add >> val >> next;
        list[add].push_back(val);
        list[add].push_back(next);
    }
    int sz = list.size();
    auto tmp = list[headv];
    int i = 0;
    while(i < sz / 2){
        tmp = list[tmp[1]];
        i++;
    }
    cout << tmp[0];
    system("pause");
    return 0;
}