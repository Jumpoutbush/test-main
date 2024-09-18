#include<bits/stdc++.h>
using namespace std;
float vec[100010][3] = {0};
vector<float> bet;//ansnumber
vector<int> ans;//WTL
int main()
{
    float num;
    int col = 0, row = 0;
    while(scanf("%f",&num) != EOF){
        if(col >= 3){
            row++; col = col % 3;
        }
        vec[row][col] = num;
        col++;
    }
    int flag;
    float max;
    for(int i = 0; i <= row; i++)
    {
        for(int j = 0; j < col; j++){
            max = -1.0;
            if(vec[i][j] > max){
                max = vec[i][j];
                flag = j;
            }
        }
        ans.push_back(flag);
        bet.push_back(max);
    }
    for(auto it = ans.begin(); it != ans.end(); it++){
        switch(flag)
        {
            case 0 : cout << "W ";
            case 1 : cout << "T ";
            case 2 : cout << "L ";
        }
    }
    float odd = 0;
    for(auto it = bet.begin(); it != bet.end(); it++){
        odd += *it;
    }
    cout << odd;
    return 0;
}