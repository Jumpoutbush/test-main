#include <bits/stdc++.h>
using namespace std;

int score[10];
int totalSum = 0;
int mindifference = INT_MAX;

void getmin(vector<int>& v, int start, int cnt){
    if(cnt == 5){
        int sum1 = 0;
        for(int i : v){
            sum1 += score[i];
        }
        int sum2 = totalSum - sum1;
        int diff = abs(sum1 - sum2);
        mindifference = min(mindifference, diff);
    }
    for(int i = start; i < 10; i++){
        v.push_back(i);
        getmin(v, i + 1, cnt + 1);
        v.pop_back();
    }
}

int main(){
    for(int i = 0; i < 10; i++){
        scanf("%d", &score[i]);
        totalSum += score[i];
    }
    vector<int> v;
    getmin(v, 0, 0);
    cout << mindifference << endl;
    system("pause");
    return 0;
}