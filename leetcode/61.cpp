/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

// @lc code=start
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
    ListNode* reverse(ListNode* head){
        ListNode* nhead = new ListNode(-101, head);
        auto tmp = nhead->next;
        while(tmp->next != nullptr){
            auto op = tmp->next;
            tmp->next = op->next;
            op->next = nhead->next;
            nhead->next = op;
        }
        return nhead->next;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !k){
            return head;
        }
        ListNode* tmp = head;
        int len = 0;
        while(tmp){
            len++;
            tmp = tmp->next;
        }
        int cnt = len - (k % len);
        if(cnt == len){
            return head;
        }
        tmp = head;
        while(cnt > 1){
            tmp = tmp->next;
            cnt--;
        }
        ListNode* bck = tmp->next;
        tmp->next = nullptr;
        ListNode *fnt = head;
        fnt = reverse(fnt);
        bck = reverse(bck);
        tmp = fnt;
        while(tmp->next != nullptr){tmp = tmp->next;}
        tmp->next = bck;
        fnt = reverse(fnt);
        return fnt;
    }
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode* ans = s.rotateRight(head, 2);
    while(ans != nullptr){
        cout << ans->val << " ";
        ans = ans->next;
    }
    getchar();
    return 0;
}