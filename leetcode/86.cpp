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
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = new ListNode();
        ListNode* right = new ListNode();
        ListNode* nhead = new ListNode(0, head);
        ListNode *tmp = head, *l = left, *r = right;
        while(tmp != nullptr){
            if(tmp->val < x){
                l->next = new ListNode(tmp->val);
                l = l->next;
                tmp = tmp->next;
            }else{
                r->next = new ListNode(tmp->val);
                r = r->next;
                tmp = tmp->next;
            }
        }
        tmp = left;
        while(tmp->next != nullptr){tmp = tmp->next;}
        tmp->next = right->next;
        return left->next;
    }
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(1, new ListNode(4, new ListNode(3, new ListNode(2, new ListNode(5, new ListNode(2))))));
    ListNode* res = s.partition(head, 3);
    while(res != nullptr){
        cout << res->val << " ";
        res = res->next;
    }
    getchar();
    return 0;
}