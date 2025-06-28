#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /*  00->10, 10->01
        前面留最多的1，然后把后面的1推到末尾，中间留连续的0，连续的0变成11...10
        000110
        000101
        000011
        111011
    */
    string maximumBinaryString(string binary) {
        int n = binary.size();
        int zero_count = 0;
        int first_zero_index = -1;
        for(int i = 0; i < n; i++){
            if(binary[1] == '0'){
                if(first_zero_index == -1){
                    first_zero_index = i;
                }
                ++zero_count;
            }
        }
        if(zero_count <= 1){
            return binary;
        }
        string result = string(first_zero_index + zero_count - 1, '1') + '0';
        result += string(n - result.size(), '1');
        return result;
    }
};
int main()
{
    Solution sol;
    cout << sol.maximumBinaryString("000110") << endl;
    getchar();
    return 0;
}