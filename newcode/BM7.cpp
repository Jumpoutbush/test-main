#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x):
        val(x), next(NULL){}
};
ListNode* hasCycle(ListNode* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow)
            return slow;
    }
    return NULL;
}
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    ListNode* slow = hasCycle(pHead);
    if(slow == NULL)
        return NULL;
    ListNode* fast = pHead;
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
int main()
{
    ListNode* head = new ListNode(0);
    ListNode* ptr = head;
    //char a, b, c, d; //四个括号标记
    string s;
    cin >> s;
    string temp = "0";
    int val;
    int i;
    for(i = 1; i < s.length(); i++)
    {
        if(s[i] == ',')
        {
            val = stoi(temp);
            ListNode* node = new ListNode(val);
            ptr->next = node;
            ptr = node;
            temp = "0";
        }else if(s[i] == '}')
        {
            if(temp == "0") break;
            val = stoi(temp);
            ListNode* node = new ListNode(val);
            ptr->next = node;
            ptr = node;
            break;
        }else{
            temp += s[i];
        }
    }
    i += 3;
    temp = "0";
    bool flag = true;
    ListNode* entry;
    for(i; i < s.length(); i++)
    {
        if(s[i] == ',')
        {
            val = stoi(temp);
            ListNode* node = new ListNode(val);
            ptr->next = node;
            ptr = node;
            if(flag == true)
            {
                entry = ptr;
                flag = false;
            }
            temp = "0";
        }else if(s[i] == '}')
        {
            if(temp == "0") break;
            val = stoi(temp);
            ListNode* node = new ListNode(val);
            ptr->next = node;
            ptr = node;
            temp = "0";
            node->next = entry;
            break;
        }else{
            temp += s[i];
        }
    }
    if(!hasCycle(head)){
        printf("null\n");
    }else{
        printf("%d\n", EntryNodeOfLoop(head)->val);
    }
    system("pause");
    return 0;
}