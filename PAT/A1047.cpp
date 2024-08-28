#include<bits/stdc++.h>
using namespace std;
const int maxcourse = 2520;
vector<string> course[maxcourse];
bool cmp(string a, string b)
{
    return a < b;
}
int main()
{
    int n, k, num;
    string name;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
    {
        cin >> name >> num;
        int courseid;
        for(int j = 0; j < num; j++)
        {
            scanf("%d", &courseid);
            course[courseid].push_back(name);
        }
    }
    for(int i = 1; i <= k; i++)
    {
        sort(course[i].begin(), course[i].end(), cmp);
    }
    for(int i = 1; i <= k; i++)
    {
        printf("%d %d\n", i, course[i].size());
        for(int j = 0; j < course[i].size(); j++)
        {
            printf("%s\n", course[i][j]);
        }
    }
    system("pause");
    return 0;
}