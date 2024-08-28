#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a[10] = {1,2,2,3,3,3,5,5,5,5};
    //寻找-1
    int* lowerPos = lower_bound(a,a+10,-1);
    int* upperPos = upper_bound(a,a+10,-1);
    printf("%d, %d\n",lowerPos - a,upperPos - a);
    //寻找1
    lowerPos = lower_bound(a,a+10,1);
    upperPos = upper_bound(a,a+10,1);
    printf("%d, %d\n",lowerPos - a,upperPos - a);
    //寻找3
    lowerPos = lower_bound(a,a+10,3);
    upperPos = upper_bound(a,a+10,3);
    printf("%d, %d\n",lowerPos - a,upperPos - a);
    //寻找4
    lowerPos = lower_bound(a,a+10,4);
    upperPos = upper_bound(a,a+10,4);
    printf("%d, %d\n",lowerPos - a,upperPos - a);
    //寻找6
    lowerPos = lower_bound(a,a+10,6);
    upperPos = upper_bound(a,a+10,6);
    printf("%d, %d\n",lowerPos - a,upperPos - a);

    system("pause");
    return 0;
}