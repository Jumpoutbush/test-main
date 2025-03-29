#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        path += '/';
        string res = "";
        stack<string> st;
        for(int i = 0; i < path.length(); ++i) {
            if(path[i] == '/' || i == path.length() - 1) {
                if(res == ".") {
                    res = "";
                    continue;
                } else if(res == "..") {
                    res = "";
                    if(!st.empty())
                        st.pop();
                } else {
                    if(res.length() > 0) {
                        st.push(res);
                        res = "";
                    }
                }
            } else {
                res += path[i];
            }
        }
        if(st.empty() && res.length() == 0) {
            return "/";
        } else {
            while(!st.empty()) {
                string sub = st.top();
                st.pop();
                if(sub.length() > 0)
                    res = "/" + sub + res;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    string path = "/a//b////c/d//././/..";
    cout << s.simplifyPath(path) << endl;
    getchar();
    return 0;
}    