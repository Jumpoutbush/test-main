#include <iostream>
#include <vector>
#include <queue>
std::vector<int> v;
bool flag = true;
struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int a) : val(a), left(nullptr), right(nullptr){}
};

void insert(TreeNode* &root, int x)
{
    if(root == nullptr){
        root = new TreeNode(x);
        return;
    }
    if(x == root->val){
        return;
    } else if(x > root->val){
        insert(root->right, x);
    } else {
        insert(root->left, x);
    }
}

TreeNode* CreateTree(std::vector<int> v)
{
    TreeNode* root = nullptr;
    for(int i = 0; i < v.size(); i++)
    {
        insert(root, v[i]);
    }
    return root;
}

void midOrder(TreeNode* root){
    if(root == nullptr)
        return;
    midOrder(root->left);
    v.push_back(root->val);
    midOrder(root->right);
}
bool isValidBST(TreeNode* root) {
    // write code here
    midOrder(root);
    for(int i = 1; i < v.size() - 1; i++)
    {
        if(v[i] < v[i - 1] || v[i] > v[i + 1])
            flag = false;
    }
    return flag;
}
std::queue<TreeNode*> q;
void levelOrder(TreeNode* root){
    if(root == nullptr)
        return;
    q.push(root);
    while(!q.empty())
    {
        int cnt = q.size();
        for(int i = 0; i < cnt; i++)
        {
            TreeNode* now = q.front();
            q.pop();
            std::cout << now->val << " ";
            if(now->left != nullptr) q.push(now->left);
            if(now->right != nullptr) q.push(now->right);
        }
        std::cout << std::endl;
    }
}
int main()
{
    std::vector<int> v_init;
    v_init.push_back(4);
    v_init.push_back(3);
    v_init.push_back(6);
    v_init.push_back(9);
    v_init.push_back(8);
    v_init.push_back(7);
    TreeNode* tree1 = CreateTree(v_init);
    levelOrder(tree1);
    if(isValidBST(tree1)){
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }
    system("pause");
    return 0;
}