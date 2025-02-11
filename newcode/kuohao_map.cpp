#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string s;
	map<char,int> pipei;
	pipei['{']=4; pipei['[']=3; pipei['(']=2; pipei['<']=1;
	for(int j=1;j<=n;++j)
	{
		cin>>s;
		stack<char>st;		
		for(int i=0;i<s.size();++i)
		{
			if(!st.empty())
			{
				if((st.top()=='('&&s[i]==')')||(st.top()=='['&&s[i]==']')||(st.top()=='<'&&s[i]=='>')||(st.top()=='{'&&s[i]=='}'))
				{
					st.pop();
				}
				else
				{
					if(pipei[st.top()]<pipei[s[i]])
					{
						break;
					}
					st.push(s[i]);
				}
			}
			else st.push(s[i]);
		}
		if(!st.empty()) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
		
	}
	return 0;
} 