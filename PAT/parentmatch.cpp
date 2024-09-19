#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
    cin >> s;
    map<char, int> pipei;
    pipei['{'] = 4; pipei['['] = 3; pipei['('] = 2; pipei['<'] = 1;

    stack<char> st;
    for(int i = 0; i < s.length(); i++)
    {
        if(!st.empty())
        {
            if((st.top()=='('&&s[i]==')') || (st.top()=='['&&s[i]==']') ||(st.top()=='<'&&s[i]=='>')||(st.top()=='{'&&s[i]=='}'))
            {
                st.pop();   //匹配到了
            }else {
                if(pipei[st.top()] < pipei[s[i]]){  //优先级嵌套错误
                    break;
                }
                st.push(s[i]);
            }
        }else{
            st.push(s[i]);
        }
    }
    if(!st.empty())
        cout << "no" << endl;
    else
        cout << "yes" << endl;
    return 0;
}