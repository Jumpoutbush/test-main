#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int _val):val(_val), left(nullptr), right(nullptr){}
};

void insert(TreeNode* &root, int x){
    if(root == nullptr){
        root = new TreeNode(x);
    }
    if(root->val == x){
        return;
    }else if(root->val > x){
        insert(root->left, x);
    }else{
        insert(root->right, x);
    }
}

TreeNode* createTree(vector<int>& v){
    TreeNode* root = nullptr;
    for(int i = 0; i < v.size(); i++){
        insert(root, v[i]);
    }
    return root;
}

// 非递归中序遍历
vector<int> inorder(TreeNode* root){
    vector<int> res;
    stack<TreeNode*> stk;
    TreeNode *cur = root;

    while(cur || !stk.empty()){
        while(cur){
            stk.push(cur);
            cur = cur->left;
        }
        cur = stk.top();
        stk.pop();
        res.push_back(cur->val);
        cur = cur->right;
    }
    return res;
}

// 非递归后序遍历
vector<int> postorder(TreeNode* root){
    vector<int> res;
    if(!root) return res;
    stack<TreeNode*> stk;
    TreeNode* cur = root;
    TreeNode* last = nullptr;

    while(cur || !stk.empty()){
        if(cur){    // 处理左
            stk.push(cur);
            cur = cur->left;
        }else{  
            // 处理右
            TreeNode* peek = stk.top();
            if(peek->right && peek->right != last){
                cur = peek->right;
            }else{  
                // 处理根
                res.push_back(peek->val);
                last = peek;
                stk.pop();
            }
        }
    }
    return res;
}
int main()
{
    vector<int> v = {5,3,6,1,4,8};
    TreeNode* root = createTree(v);
    vector<int> in = inorder(root);
    for(int i = 0; i < in.size(); i++){
        cout << in[i];
        if(i < in.size()) cout << " ";
    }
    cout << endl;

    vector<int> post = postorder(root);
    for(int i = 0; i < post.size(); i++){
        cout << post[i];
        if(i < post.size()) cout << " ";
    }
    getchar();
    return 0;
}