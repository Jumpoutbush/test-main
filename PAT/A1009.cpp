#include<bits/stdc++.h>
using namespace std;
struct Node{
    double coefficient;
    int exponent;
}node;
double a[2005] = {0};
int main()
{
    int K1;
    scanf("%d", &K1);
    vector<Node> v1, v2, vres;
    for(int i = 0; i < K1; i++){
        cin >> node.exponent >> node.coefficient;
        v1.push_back(node);
    }
    int K2;
    scanf("%d", &K2);
    for(int i = 0; i < K2; i++){
        cin >> node.exponent >> node.coefficient;
        v2.push_back(node);
    }
    for(int i = 0; i < K1; i++){
        for(int j = 0; j < K2; j++){
            node.coefficient = v1[i].coefficient * v2[j].coefficient;
            node.exponent = v1[i].exponent + v2[j].exponent;
            vres.push_back(node);
        }
    }
    for(int i = 0; i < vres.size(); i++){
        a[vres[i].exponent] += vres[i].coefficient;
    }
    vector<Node> vfinal;
    for(int i = 2005; i >= 0; i--){
        if(a[i]!=0){
            node.coefficient = a[i];
            node.exponent = i;
            vfinal.push_back(node);
        }
    }
    cout << vfinal.size() << " ";
    for(int i = 0; i < vfinal.size()-1; i++){
        printf("%d %.1f ", vfinal[i].exponent, vfinal[i].coefficient);
    }
    printf("%d %.1f", vfinal[vfinal.size()-1].exponent, vfinal[vfinal.size()-1].coefficient);
    system("pause");
    return 0;
}