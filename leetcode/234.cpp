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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* cur = head;
        if (fast) {
            cur = slow;
        } else {
            while (cur->next != slow) {
                cur = cur->next;
            }
        }
        ListNode* pre = cur->next;
        ListNode* tmp = pre->next;
        while (tmp != nullptr) {
            pre->next = tmp->next;
            tmp->next = cur->next;
            cur->next = tmp;
            tmp = pre->next;
        }
        ListNode* fnt = head;
        ListNode* beh = cur->next;
        while (beh) {
            if (beh->val != fnt->val) {
                return false;
            }
            beh = beh->next;
            fnt = fnt->next;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode{0};
    ListNode* third = new ListNode{1};
    // ListNode* fourth = new ListNode{1};
    first->next = second;
    second->next = third;
    // third->next = fourth;
    if(sol.isPalindrome(first))
    {
        cout << "true" << endl;
    }
    getchar();
    return 0;
}