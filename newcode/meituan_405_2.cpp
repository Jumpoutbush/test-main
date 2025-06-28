 #include <bits/stdc++.h>
 using namespace std;
 const int maxn = 1e6 + 10;
 vector<int> prime(maxn);
 vector<bool> p(maxn, 0);
 void Find_Prime(){
    for(int i = 2; i <= maxn; i++){
        if(p[i] == false){
            prime.push_back(i);
            for(int j = i + i; j <= maxn; j += i){
                p[j] = true;
            }
        }
    }
 }


 int main()
 {
    int n;
    cin >> n;
    int cnt = 0;
    vector<bool> vis(n + 1);
    for(int i = 2; i <= n; i++){
        for(int p : prime){
            
        }
    }
 }