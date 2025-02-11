#include <vector>
struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int v) : val(v){}
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
    } else{
        insert(root->left, x);
    }
}

TreeNode* create(std::vector<int> inp)
{
    TreeNode* root = nullptr;
    for(int & i : inp)
    {
        insert(root, inp[i]);
    }
    return root;
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
    TreeNode* tree1 = create(v_init);
    
    return 0;
}