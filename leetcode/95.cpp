#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void createTree(TreeNode* &root, int x){
        if(!root){
            root = new TreeNode(x);
            return;
        }
        if(root->val == x){
            return;
        }else if(root->val < x){
            createTree(root->right, x);
        }else if(root->val > x){
            createTree(root->left, x);
        }
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        vector<int> v;
        for(int i = 1; i <= n; ++i){
            v.push_back(i);
        }
        do{
            TreeNode* root = nullptr;
            for(int i = 0; i < n; ++i){
                createTree(root, v[i]);
            }
            ans.push_back(root);
        }while(next_permutation(v.begin(), v.end()));
        return ans;
    }
};

int main()
{
    Solution s;
    s.generateTrees(3);
    return 0;
}