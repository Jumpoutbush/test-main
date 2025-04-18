//Head of a Gang
#include<iostream>
#include<map>
#include<string>
using namespace std;
const int maxn = 2010;
const int INF = 1000000000;

map<int, string> intToString;
map<string, int> stringToInt;
map<string, int> Gang;
int G[maxn][maxn] = {0},weight[maxn] = {0};
int n, k, numPerson = 0;
bool vis[maxn] = {false};

void DFS(int nowVisit,int &head, int &numMember, int &totalValue){
    numMember++;//组成员+1
    vis[nowVisit] = true;//访问标记
    if(weight[nowVisit] > weight[head]){//权值大者做Gang
        head = nowVisit;
    }
    for(int i=0;i<numPerson;i++){//枚举所有人
        if(G[nowVisit][i] > 0){//能从nowVisit到达i
            totalValue += G[nowVisit][i];//连通分量总边权增加该边权
            G[nowVisit][i] = G[i][nowVisit] = 0;//删除该边防止回头路
            if(vis[i] == false){
                DFS(i, head, numMember, totalValue);
            }
        }
    }
}
void DFSTraverse(){
    for(int i=0;i<numPerson;i++){//枚举所有人
        if(vis[i] == false){
            int head = i,numMember = 0, totalValue = 0;//头目、成员数、总边权
            DFS(i, head, numMember, totalValue);//遍历i所在连通块
            if(numMember > 2 && totalValue > k){//成员数>2且总边权>k
                Gang[intToString[head]] = numMember;//head人数为numMember,该值在DFS中增加
            }
        }
    }
}
int change(string str){
    if(stringToInt.find(str) != stringToInt.end()){
        return stringToInt[str];
    }else{
        stringToInt[str] = numPerson;
        intToString[numPerson] = str;
        return numPerson++;
    }
}
int main(){
    int w;
    string str1,str2;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>str1>>str2>>w;
        int id1 = change(str1);
        int id2 = change(str2);
        weight[id1] += w;
        weight[id2] += w;
        G[id1][id2] += w;
        G[id2][id1] += w;
    }
    DFSTraverse();
    cout<<Gang.size()<<endl;
    map<string, int>::iterator it;
    for(it = Gang.begin();it!=Gang.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    system("pause");
    return 0;
}