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

void insert(TreeNode* &root, int x){
    if(root == nullptr){
        root = new TreeNode(x);
        return;
    }
    if(root->val == x){
        return;
    }else if(root->val > x){
        insert(root->left, x);
    }else{
        insert(root->right, x);
    }
}

TreeNode* createTree(std::vector<int>& v){
    TreeNode* root = nullptr;
    for(int i = 0; i < v.size(); i++){
        insert(root, v[i]);
    }
    return root;
}

bool isValidBST(TreeNode* root) {
    bool isvalid;
    if(!root) return true;
    if(root->left == nullptr && root->right == nullptr){
        isvalid = true;
    }else if(root->left != nullptr && root->right == nullptr){
        isvalid = root->left->val < root->val;
    }else if(root->left == nullptr && root->right != nullptr){
        isvalid = root->right->val > root->val;
    }else{
        isvalid = root->left->val < root->val && root->right->val > root->val;
    }
    bool lvalid = isValidBST(root->left);
    bool rvalid = isValidBST(root->right);
    return isvalid && lvalid && rvalid;
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
    std::vector<int> v_init = {4, 3, 6, 9, 8, 7};
    TreeNode* tree1 = createTree(v_init);
    levelOrder(tree1);
    if(isValidBST(tree1)){
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }
    system("pause");
    return 0;
}