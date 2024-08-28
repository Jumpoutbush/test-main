#include<iostream>
using namespace std;
const int left = 1;
int getright(int A[],int n){
    int temp=-1;
    for(int i=0;i<n;i++){
        if(temp<A[i]){
            temp = A[i];
        }
    }
    return temp;
}
int k(int A[],int L,int n){
    int count = 0;
    for(int i=0 ; i< n ; i++){
        count += A[i] / L ;
    }
    return count;
}
int solve (int A[],int K,int n){
    int left = 1,right = getright(A,n),mid;
    while (left<right){
        mid = (left + right) / 2;
        if(k(A,mid,n)>K){
            left =  mid + 1;
        }else{
            right = mid;
        }
    }
    return left;
}
int main(){
    int n;
    int A[10010]={0};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cout<<solve(A,6,n);
    system("pause");
    return 0;
}
