#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> vi;
    for(int i=1;i<=5;i++){
        vi.push_back(i);
    }
    vector<int>::iterator it = vi.begin();
    for(int i=0;i<5;i++){
        printf("%d",*(it+i));//vi[i]和*(vi.begin()+i)是等价的
    }
    for(vector<int>::iterator it2 = vi.begin();it2!=vi.end();it2++){
        printf("%d",*it2);
    }
    system("pause");
    return 0;
}