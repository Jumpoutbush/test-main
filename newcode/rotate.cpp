#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// abcd123->dcba 321->123abcd
void rotate(string& s, int r){
    int n = s.length();
    if(n < 2) return;
    reverse(s.begin(), s.begin() + (n - r));
    reverse(s.begin() + (n - r), s.end());
    reverse(s.begin(), s.end());
}
int main()
{
    string s = "abcdefg123";
    rotate(s, 3);
    cout << s;
    getchar();
    return 0;
}