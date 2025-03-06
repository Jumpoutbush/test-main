#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    std::string decodeString(std::string s) {
        std::string res;
        int multi = 0;
        std::stack<int> stack_multi;
        std::stack<std::string> stack_res;

        for (char c : s) {
            if (c == '[') {
                stack_multi.push(multi);
                stack_res.push(res);
                multi = 0;
                res = "";
            } else if (c == ']') {
                std::string tmp;
                int cur_multi = stack_multi.top();
                stack_multi.pop();
                for (int i = 0; i < cur_multi; ++i) {
                    tmp += res;
                }
                res = stack_res.top() + tmp;
                stack_res.pop();
            } else if (isdigit(c)) {
                multi = multi * 10 + (c - '0');
            } else {
                res += c;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::string s1 = "3[a]2[bc]";
    std::string s2 = "3[a2[c]]";
    std::cout << sol.decodeString(s1) << std::endl;
    std::cout << sol.decodeString(s2) << std::endl;
    return 0;
}