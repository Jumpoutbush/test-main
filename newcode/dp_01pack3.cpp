// 带子物品条件的0/1背包问题
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item{
    int price;
    int importance;
};

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<Item> mainItems(m + 1);
    vector<vector<Item>> accessories(m + 1);

    for(int i = 1; i <= m; i++){
        int price, importance, parent;
        cin >> price >> importance >> parent;

        Item item = {price, importance};
        if(parent == 0){
            mainItems[i] = item;
        } else {
            accessories[parent].push_back(item);
        }
    }

    vector<int> dp(n + 1, 0);

    for(int i = 1; i <= m; i++){
        if(mainItems[i].price > 0){
            int mainPrice = mainItems[i].price;
            int mainValue = mainItems[i].price * mainItems[i].importance;
            vector<int> temp = dp;
            
            // 只买主件
            for(int j = n; j >= mainPrice; --j){
                temp[j] = max(temp[j], temp[j - mainPrice] + mainValue);
            }

            // 购买主件和附件   
            for(int j = n; j >= mainPrice; --j){
                int totalValue = mainValue;
                int totalPrice = mainPrice;
                for(auto& acc : accessories[i]){
                    totalPrice += acc.price;
                    totalValue += acc.price * acc.importance;
                    if(j >= totalPrice){
                        temp[j] = max(temp[j], dp[j - totalPrice] + totalValue);
                    } else {
                        break;
                    }
                }
            }
            dp = temp;
        }
    }

    printf("%d", dp[n]);
    return 0;
}
