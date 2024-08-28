#include<bits/stdc++.h>
using namespace std;
const int maxn = 35;
struct node{
    int data;
    node* lchild;
    node* rchild;
};
int pre[maxn], in[maxn], post[maxn];
int n;
node* create(int postL, int postR, int inL, int inR)
{
    if(postL > postR)
        return nullptr;
    node* root = new node;
    root->data = post[postR];
    int k;
    for(k = inL; k <= inR; k++)
    {
        if(in[k] == post[postR])
        {
            break;
        }
    }
    int numLeft = k - inL;
    root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);
    root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
    return root;
}
int num = 0;
void BFS(node* root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* top = q.front();
        q.pop();
        cout << top->data;
        num++;
        if(num < n) cout << " ";
        if(top->lchild!=nullptr) q.push(top->lchild);
        if(top->rchild!=nullptr) q.push(top->rchild);
    }
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> post[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> in[i];
    }
    node* root = create(0, n-1, 0, n-1);
    BFS(root);
    return 0;
}