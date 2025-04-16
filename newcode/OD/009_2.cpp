// 需要广播的服务器数量(并查集)
#include <bits/stdc++.h>
using namespace std;

class UFSet{
private:
    vector<int> parent;
    vector<int> rank;
public:
    UFSet(int N){
        parent.resize(N);
        rank.resize(N, 0);
        for(int i = 0; i < N; i++){
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void union(int x, int y){
        
    }
};