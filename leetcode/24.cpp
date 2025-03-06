#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head){
            return nullptr;
        }else if(!head->next){
            return head;
        }
        ListNode* nhead = new ListNode(-1);
        nhead->next = head;
        auto swaphead = nhead;
        auto pre = swaphead->next;
        auto nxt = pre->next;
        int cnt = 2;
        while(swaphead->next != nullptr){
            cnt = 2;
            while(cnt > 1){
                pre->next = nxt->next;
                swaphead->next = nxt;
                nxt->next = pre;
                swaphead = pre;
                pre = swaphead->next;
                if(pre != nullptr)
                    nxt = pre->next;
                cnt--;
            }
        }
        return nhead->next;
    }
};

int main()
{
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);
    a->next = b;
    b->next = c;
    c->next = d;
    Solution sol;
    ListNode* r = sol.swapPairs(a);
    return 0;
}