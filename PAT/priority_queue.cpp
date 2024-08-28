// #include<iostream>
// #include<string>
// #include<queue>
// using namespace std;
// struct fruit{
//     string name;
//     int price;
//     friend bool operator < (fruit f1,fruit f2){
//         return f1.price < f2.price;
//     }
// }f1,f2,f3;
// int main(){
//     priority_queue<fruit> q;
//     f1.name = "peach";
//     f1.price = 3;
//     f2.name = "pear";
//     f2.price = 4;
//     f3.name = "apple";
//     f3.price = 1;
//     q.push(f1);
//     q.push(f2);
//     q.push(f3);
//     cout<<q.top().name<<" "<<q.top().price<<endl;
//     system("pause");
//     return 0;
// }
// int main(){
//     priority_queue<int,vector<int>,greater<int> > q;
//     q.push(3);
//     q.push(4);
//     q.push(1);
//     printf("%d\n",q.top());
//     system("pause");
//     return 0;
// }
#include<iostream>
#include<string>
#include<queue>
using namespace std;
struct fruit{
    string name;
    int price;
}f1,f2,f3;
struct cmp{
    bool operator () (const fruit &f1,const fruit &f2){
        return f1.price > f2.price;
    }
};
int main(){
   priority_queue<fruit,vector<fruit>, cmp> q;
    f1.name = "peach";
    f1.price = 3;
    f2.name = "pear";
    f2.price = 4;
    f3.name = "apple";
    f3.price = 1;
    q.push(f1);
    q.push(f2);
    q.push(f3);
    cout<<q.top().name<<" "<<q.top().price<<endl;
    system("pause");
    return 0;
}