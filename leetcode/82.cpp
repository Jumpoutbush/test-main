#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
ListNode *next;
    ListNode() : val(0), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* nhead = new ListNode{-101, head};
        auto pre = nhead, tmp = nhead->next;
        bool flag = false;      // false代表不需要删除，直接跳过
        while(tmp != nullptr){
            auto tail = tmp->next;
            while(tail && tail->val == tmp->val){
                tail = tail->next;
                flag = true;
            }
            if(flag){
                pre->next = tail;
                tmp = tail;
                flag = false;
            }else{
                 pre = tmp;
                tmp = tmp->next;
            }
        }
        return nhead->next;
    }
};

int main(){
    // ListNode* head = new ListNode{1, new ListNode{1, new ListNode{1, new ListNode{2, new ListNode{3, new ListNode{3, nullptr}}}}};
    ListNode* head = new ListNode{1, new ListNode{2, new ListNode{3, new ListNode{3, new ListNode{4, new ListNode{4, new ListNode{5, nullptr}}}}}}};
    Solution sol;
    auto ans = sol.deleteDuplicates(head);
    while(ans != nullptr){
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
    getchar(); 
    return 0;
}