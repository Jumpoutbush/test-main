#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int _val):val(_val), left(nullptr), right(nullptr){}
};

TreeNode* createTree(vector<int>& v){
    if(v.size() == 0) return nullptr;
    TreeNode* root = new TreeNode(v[0]);
    queue<TreeNode*> q;
    int i = 1, n = v.size();
    q.push(root);
    while(!q.empty() && i < n){
        TreeNode* cur = q.front();
        q.pop();
        if(i < n){
            if(cur->left == nullptr){
                TreeNode* lnode = new TreeNode(v[i]);
                q.push(lnode);
                cur->left = lnode;
                i++;
            }
        }
        if(i < n){
            if(cur->right == nullptr){
                TreeNode* rnode = new TreeNode(v[i]);
                q.push(rnode);
                cur->right = rnode;
                i++;
            }
        }
    }
    return root;
}
void levelorder(TreeNode* &root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* cur = q.front();
        q.pop();
        cout << cur->val << " ";
        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
    }
}

int dfs(TreeNode* &root){
    if(root->val == -1 || !root){
        return 0;
    }
    int left = 0, right = 0;
    if(root->left)
        left = dfs(root->left);
    if(root->right)
        right = dfs(root->right);
    return root->val + max(left, right);
}

int main()
{
    string str;
    getline(cin, str);
    vector<int> treevec;

    string tmp = "";
    for(char& c : str){
        if(c == ' '){
            treevec.push_back(stoi(tmp));
            tmp.clear();
        }else{
            tmp += c;
        }
    }
    treevec.push_back(stoi(tmp));

    TreeNode* root = createTree(treevec);
    cout << dfs(root);
    system("pause");
    return 0;
}