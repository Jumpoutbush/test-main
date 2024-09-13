#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    int p = 1;
    set<int> st;
    while(p<=T)
    {
        int n;
        scanf("%d", &n);
        st.clear();
        int num;
        int max = -1;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &num);
            if(num > max) max = num;
            st.insert(num);
        }
        int sz = st.size();
        bool flag = false;
        for(auto it = st.begin(); it != st.end(); it++)
        {
            set<int>::iterator it1 = it;
            for(set<int>::iterator it2 = ++it1; it2 != st.end(); it2++)
            {
                int newnum = *it + *it2;
                if(newnum > max) break;
                st.insert(newnum);
                if(st.size() == sz)
                {
                    flag = true;
                    break;
                }else{
                    st.erase(newnum);
                }
                
            }
            if(flag == true)
                break;
        }
        if(flag == true)
        {
            cout << "Case " << p << ": NO" << endl;
        }else{
            cout << "Case " << p << ": YES" << endl;
        }
        p++;
    }
    system("pause");
    return 0;
}