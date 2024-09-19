#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left, *right;
};

int n, num = 0;

void insert(node* &root, int data)
{
    if(root == nullptr)
    {
        root = new node;
        root->data = data;
        root->left = root->right = nullptr;
        return;
    }
    if(data < root->data) insert(root->left, data);
    else insert(root->right, data);
}
void BFS(node* root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* front = q.front();
        q.pop();
        printf("%d", front->data);
        num++;
        if(num < n){
            printf(" ");
        }else{
            printf("\n");
        }
        if(front->left != nullptr) q.push(front->left);
        if(front->right != nullptr) q.push(front->right);
    }
}
vector<int> origin;

int main()
{
    int data;
    node* root = nullptr;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        origin.push_back(data);
        insert(root, data);
    }
    BFS(root);
    system("pause");
    return 0;
}