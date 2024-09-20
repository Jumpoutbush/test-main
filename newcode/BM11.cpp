
 struct ListNode {
 int val;
 struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
    ListNode* ReverseList(ListNode*& head) {
        // write code here
        if (head == nullptr) return head;
        ListNode* ptr = head;
        while (ptr->next != nullptr) {
            ListNode* temp = ptr->next;
            ptr->next = temp->next;
            temp->next = head;
            head = temp;
        }
        return head;
    }
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        // write code here
        if (head1 == nullptr) return head2;
        if (head2 == nullptr) return head1;
        ReverseList(head1);
        ReverseList(head2);
        int carry = 0;
        ListNode* p1 = head1, *p2 = head2;
        ListNode* nHead = new ListNode(-1);
        ListNode* ptr = nHead;
        while (p1 != nullptr && p2 != nullptr) {
            ListNode* cur = new ListNode(0);
            cur->val = (p1->val + p2->val + carry) % 10;
            if (p1->val + p2->val + carry >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }
            ptr->next = cur;
            ptr = cur;
            p1 = p1->next;
            p2 = p2->next;
        }
        if (p1 != nullptr) {
            while (p1 != nullptr) {
                ListNode* cur = new ListNode(0);
                cur->val = (p1->val + carry) % 10;
                if (p1->val + carry >= 10) {
                    carry = 1;
                } else {
                    carry = 0;
                }
                ptr->next = cur;
                ptr = cur;
                p1 = p1->next;
            }
            if (carry == 1) {
                ListNode* cur = new ListNode(1);
                ptr->next = cur;
            }
        }

        if (p2 != nullptr) {
            while (p2 != nullptr) {
                ListNode* cur = new ListNode(0);
                cur->val = (p2->val + carry) % 10;
                if (p2->val + carry >= 10) {
                    carry = 1;
                } else {
                    carry = 0;
                }
                ptr->next = cur;
                ptr = cur;
                p2 = p2->next;
            }
            if (carry == 1) {
                ListNode* cur = new ListNode(1);
                ptr->next = cur;
            }
        }
        ReverseList(nHead->next);
        return nHead->next;
    }
};