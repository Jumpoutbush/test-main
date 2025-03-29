#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isdigital(const string& str){
        return !(str == "+" || str == "-" || str == "*" || str == "/");
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        for(int i = 0; i < n; ++i){
            string& token = tokens[i];
            if(isdigital(token)){
                st.push(stoi(token));
            }else{
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                switch(token[0]){
                    case '+':
                        st.push(num1 + num2);
                        break;
                    case '-':
                        st.push(num1 - num2);
                        break;
                    case '*':
                        st.push(num1 * num2);
                        break;
                    case '/':
                        st.push(num1 / num2);
                        break;
                }
            }
        }
        return st.top();
    }
};

int main()
{
    Solution s;
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << s.evalRPN(tokens) << endl;
    getchar();
    return 0;
}