#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

map<string, int> real = {
    {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6}, {"7", 7}, {"8", 8}, {"9", 9}, {"10", 10}, {"J", 11}, {"Q", 12}, {"K", 13}, {"A", 1}
};
vector<string> findroute(vector<string> v){
    map<string, int> m; // key: card, value: count
    vector<string> res;
    for(int i = 0; i < v.size(); ++i){
        m[v[i]]++; // count the number of each card
    }
    sort(m.begin(), m.end());
    int left = 0, right = v.size() - 1;
    int cnt = -1;
    for(auto it = m.begin(); it != m.end(); ++it){
        if(real[it->first] > 2 && it->second > 0){
            string card1 = it->first;
            left = real[card1];
            for(auto it2 = it; it2 != m.end(); ++it2){
                if(it2->second > 0){
                    string card2 = it2->first;
                    right = real[card2];
                }
            }
        }
        cnt = max(cnt, right - left + 1);
        if(cnt >= 5){
            for(int i = left; i <= right; ++i){
                res.push_back(to_string(i));
            }
        }
    }
    return res;
}
int main()
{
    vector<string> v = {"2", "9", "J", "10", "3", "4", "K", "A", "7", "Q", "A", "5", "6"};
    vector<string> res = findroute(v);
    for(auto & i : res){
        cout << i << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}