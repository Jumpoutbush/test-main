#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    priority_queue<int, vector<int>, less<int>> prices;
    for(int i = 0; i < n; i++){
        int price;
        cin >> price;
        prices.push(price);
    }
    vector<pair<int, int>> tokens;
    for(int i = 0; i < m; i++){
        int low, p;
        cin >> low >> p;
        tokens.emplace_back(low, p);
    }
    sort(tokens.begin(), tokens.end(), [&tokens](pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    });
    int save = 0;
    for(auto token : tokens){
        for(int i = 0; i < m; i++){
            int price = prices.top();
            prices.pop();
            if(price >= token.first){
                price -= token.second;
                save += token.second;
                //prices.push(price);
                break;
            }else{
                break;
            }
        }
    }
    cout << save << endl;
    system("pause");
    return 0;
}