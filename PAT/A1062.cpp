#include<bits/stdc++.h>
#include<cstring>
using namespace std;
struct Student{
    char id[10];
    int de, cai, sum;
    int flag;
}stu[100010];

bool cmp(Student a, Student b)
{
    if(a.flag != b.flag) return a.flag < b.flag;
    else if(a.sum != b.sum) return a.sum > b.sum;
    else if(a.de != b.de) return a.de > b.de;
    else return strcmp(a.id, b.id) < 0;
}
int main()
{
    int N, L, H;
    scanf("%d%d%d", &N, &L, &H);
    int m = N;
    for(int i = 0; i < N; i++)
    {
        cin >> stu[i].id >> stu[i].de >> stu[i].cai;
        stu[i].sum = stu[i].de + stu[i].cai;
        if(stu[i].de < L || stu[i].cai < L)
        {
            stu[i].flag = 5;
            m--;
        }
        else if(stu[i].de >= H && stu[i].cai >= H) stu[i].flag = 1;
        else if(stu[i].de >= H && stu[i].cai < H) stu[i].flag = 2;
        else if(stu[i].de >= stu[i].cai) stu[i].flag = 3;
        else stu[i].flag = 4;
    }
    sort(stu, stu + N, cmp);
    printf("%d\n", m);
    for(int i = 0; i < m; i++)
    {
        printf("%s %d %d\n", stu[i].id, stu[i].de, stu[i].cai);
    }
    return 0;
}