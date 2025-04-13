#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// 比较字符串是否小于等于（考虑长度和字典序）
bool is_less_or_equal(const string& s1, const string& s2) {
    if (s1.length() < s2.length()) return true;
    if (s1.length() > s2.length()) return false;
    return s1 <= s2;
}

// 将字符串从位置i开始降序排列（最大化后续部分）
void max_suffix(string& s, int i) {
    vector<char> chars(s.begin() + i, s.end());
    sort(chars.rbegin(), chars.rend()); // 降序排列
    for (int j = 0; j < chars.size(); j++) {
        s[i + j] = chars[j];
    }
}

string maximize_not_exceed(const string& s1, const string& s2) {
    string res = s1;
    int n = res.length();
    int m = s2.length();
    
    if (n < m) {
        // 长度更短，直接最大化
        max_suffix(res, 0);
        return res;
    } else if (n > m) {
        // 长度更长，无法满足（根据题意处理，此处返回空）
        return "";
    }
    
    bool less = false;
    for (int i = 0; i < n; i++) {
        if (less) {
            // 后续位可完全最大化
            max_suffix(res, i);
            break;
        }
        char target = s2[i];
        char max_d = '0';
        int max_pos = i;
        // 寻找i到末尾中不超过target的最大字符，且尽可能靠右（保留左侧更小字符，给右侧更多空间）
        for (int j = i; j < n; j++) {
            if (res[j] <= target && res[j] >= max_d) {
                max_d = res[j];
                max_pos = j;
            }
        }
        if (max_d < target) {
            // 选择max_d，交换后后续位最大化
            swap(res[i], res[max_pos]);
            max_suffix(res, i + 1);
            less = true;
        } else if (max_d == target) {
            // 必须选择等于target的字符，交换到当前位（优先选右侧，保留左侧小字符）
            // 寻找最右侧的max_d，以便后续位有更多调整空间
            int rightmost = i;
            for (int j = n - 1; j >= i; j--) {
                if (res[j] == target) {
                    rightmost = j;
                    break;
                }
            }
            swap(res[i], res[rightmost]);
            // 若交换的是自己，无需处理；否则，后续位可能仍需受限
        } else {
            // 无法选择更大的字符（已被条件限制），保持现状
            continue;
        }
    }
    // 处理完全相等的情况（若最终结果大于s2，说明无解，返回原字符串或空，此处假设输入合法）
    return is_less_or_equal(res, s2) ? res : "";
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    string result = maximize_not_exceed(str1, str2);
    cout << result << endl;
    system("pause");
    return 0;
}