#include <bits/stdc++.h>
using namespace std;
/*
    13 14 15 20 15 14
    
*/
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> t(n, 0);
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    for(int i = 0; i < n; i++){
        pq.push(make_tuple(a[i], i, 0));
    }
    for(int i = 0; i < m; i++){
        auto [key, idx, cnt] = pq.top();
        pq.pop();
        ++ cnt;
        t[idx] = cnt;
        int new_key = a[idx] + cnt * k;
        pq.push(make_tuple(new_key, idx, cnt));
    }
    for(int i = 0; i < n; i++){
        if(i > 0){
            cout << " ";
        }
        cout << a[i] - (m - t[i]) * k;
    }
    cout << endl;
    system("pause");
    return 0;
}