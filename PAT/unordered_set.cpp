#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int> st;
    for(int i =0;i<100;i++){
        st.insert(i%6);
    }
    for(unordered_set<int>::iterator it = st.begin();it!=st.end();it++){
        printf("%d",*it);
    }
    system("pause");
    return 0;
}