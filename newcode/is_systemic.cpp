#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int a) : val(a), left(nullptr), right(nullptr){}
};

TreeNode* createTreeFromVector(const vector<int>& v) {
    if(v.empty())
        return nullptr;
    TreeNode* root = new TreeNode(v[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while(!q.empty() && i < v.size()) {
        TreeNode* cur = q.front();
        if(i < v.size()){
            cur->left = new TreeNode(v[i]);
            q.push(cur->left);
            i++;
        }
        if(i < v.size()){
            cur->right = new TreeNode(v[i]);
            q.push(cur->right);
            i++;
        }
        q.pop();
    }
    return root;
}

bool issystemic(TreeNode* root)
{
    queue<TreeNode*> lq;
    queue<TreeNode*> rq;
    lq.push(root->left);
    rq.push(root->right);
    bool flag = true;

    while(!lq.empty() && !rq.empty())
    {
        auto curl = lq.front();
        auto curr = rq.front();
        cout << curl->val << " " << curr->val << " ";
        if(curl->val != curr->val){
            flag = false;
            break;
        }
        lq.pop(); rq.pop();
        if(curl->left != nullptr) lq.push(curl->left);
        if(curl->right != nullptr) lq.push(curl->right);
        if(curr->right!= nullptr) rq.push(curr->right);
        if(curr->left!= nullptr) rq.push(curr->left);
    }
    return flag;
}
int main()
{
    vector<int> v{1,2,2,3,4,4,5};
    TreeNode* root = createTreeFromVector(v);
    if(issystemic(root)){
        cout << "systemic";
    }
    getchar();
    return 0;
}