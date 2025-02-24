#include <iostream>
using namespace std;

struct Node{
    int val;
    struct Node* next;
    Node(int n) : val(n), next(nullptr){}
};

void MergeList(Node* &a, Node* b){
    Node* fa = a->next;
    Node* fb = b->next;
    Node* sa = a;
    Node* sb = b;
    while(fa != nullptr && fb != nullptr)
    {
        if(sa->val <= fb->val && fa->val > fb->val){
            Node* tmp = fb->next;
            sb->next = tmp;
            fb->next = fa;
            sa->next = fb;
            sa = sa->next;
            fb = tmp;
        } else {
            fa = fa->next;
            sa = sa->next;
        }
    }
    if(fa == nullptr){
        sa->next = fb;
    }
}

int main()
{
    int a, b;

    while(cin >> a >> b)
    {
        Node* ra = new Node(-1);
        Node* rb = new Node(-1);
        auto tmpa = ra, tmpb = rb;
        for(int i = 0; i < a; i++)
        {
            int node_value;
            scanf("%d", &node_value);
            Node* new_node = new Node(node_value);
            tmpa->next = new_node;
            tmpa = new_node;
        }
        for(int i = 0; i < b; i++)
        {
            int node_value;
            scanf("%d", &node_value);
            Node* new_node = new Node(node_value);
            tmpb->next = new_node;
            tmpb = new_node;
        }
        MergeList(ra, rb);
        tmpa = ra->next;
        while(tmpa != nullptr)
        {
            cout << tmpa->val << " ";
            tmpa = tmpa->next;
        }
    }
    return 0;
}