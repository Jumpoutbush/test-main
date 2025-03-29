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
    TreeNode* firstMax = nullptr;
    TreeNode* lastMin = nullptr;
    TreeNode* prev = new TreeNode(INT_MIN);
    void recoverTree(TreeNode* root) {
        helper(root);
        if(firstMax != nullptr && lastMin != nullptr){
            swap(firstMax->val, lastMin->val);
        }
    }

    void helper(TreeNode* root){
        if(!root) return ;
        helper(root->left);
        if(root->val < prev->val){
            lastMin = root;
            if(firstMax == nullptr)
                firstMax = prev;
        }
        prev = root;
        helper(root->right);
    }
};

int main()
{
    Solution s;
    TreeNode* root = new TreeNode(10, new TreeNode(4, new TreeNode(3), new TreeNode(5)), new TreeNode(9, new TreeNode(7), new TreeNode(6)));
    s.recoverTree(root);
    return 0;
}