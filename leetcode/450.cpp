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
    TreeNode* findNode(TreeNode*& root, int key) {
        if (root == nullptr)
            return nullptr;
        if (root->val == key)
            return root;
        TreeNode* left = findNode(root->left, key);
        TreeNode* right = findNode(root->right, key);
        if (left)
            return left;
        if (right)
            return right;
        return nullptr;
    }

    TreeNode* findParent(TreeNode*& root, int key) {
        if (root == nullptr || root->val == key)
            return nullptr;
        if (root->left && root->left->val == key)
            return root;
        if (root->right && root->right->val == key)
            return root;
        TreeNode* left = findParent(root->left, key);
        TreeNode* right = findParent(root->right, key);
        if (left)
            return left;
        if (right)
            return right;
        return nullptr;
    }

    TreeNode* deleteNode(TreeNode*& root, int key) {
        if (!root)
            return nullptr;

        TreeNode* delnode = findNode(root, key);
        if (delnode == nullptr)
            return root;
        TreeNode* newnode = delnode->right;
        if (newnode == nullptr) {
            if (delnode == root) {
                return delnode->left;
            } else {
                TreeNode* parent = findParent(root, key);
                if (parent->left == delnode) {
                    parent->left = delnode->left;
                } else {
                    parent->right = delnode->right;
                }
                return root;
            }
        }
        TreeNode* swapnode = newnode;
        TreeNode* prevnode = newnode;
        if (newnode->left != nullptr) {
            while (prevnode->left->left != nullptr) {
                prevnode = prevnode->left;
            }
            swapnode = prevnode->left;
        }
        swap(delnode->val, swapnode->val);
        if (prevnode->left != nullptr) {
            prevnode->left = swapnode->right;
        } else {
            delnode->right = newnode->right;
        }
        return root;
    }
};

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(1);
    //root->left->right = new TreeNode(4);
    Solution s;
    s.deleteNode(root, 2);
    return 0;
}