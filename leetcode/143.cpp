#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* nhead){
        ListNode* head = nhead->next;
        while(head->next != nullptr){
            ListNode* tmp = head->next;
            head->next = tmp->next;
            tmp->next = nhead->next;
            nhead->next = tmp;
        }
        return nhead->next;
    }
    void reorderList(ListNode* head) {
        ListNode* tmp = head;
        int len = 0;
        while(tmp != nullptr){
            len++;
            tmp = tmp->next;
        }
        if(len == 1) return;
        int half = len % 2 == 0 ? len / 2 : len / 2 + 1;
        tmp = head;
        while(--half){
            tmp = tmp->next;
        }
        tmp->next = reverseList(tmp);
        ListNode *fnthead = head->next, *bckhead = tmp->next;
        int cnt = 1;
        tmp = head;
        while(cnt < len){
            if(cnt % 2 == 0){
                tmp->next = fnthead;
                fnthead = fnthead->next;
            }else{
                tmp->next = bckhead;
                bckhead = bckhead->next;
            }
            tmp = tmp->next;
            cnt++;
        }
        tmp->next = bckhead;
    }
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    //head->next->next->next->next = new ListNode(5);
    s.reorderList(head);
    ListNode* res = head;
    while(res != nullptr){
        cout << res->val << " ";
        res = res->next;
    }
    getchar();
    return 0;
}