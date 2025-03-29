#include <iostream>

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) {
            return root;
        }
        return left ? left : right; 
    }
};

void freeTree(TreeNode* root) {
    delete root;
    freeTree(root->left);
}

int main() {
    // 创建一个简单的二叉树
    //       3
    //      / \
    //     5   1
    //    /|   |\
    //   6 2   0 8
    //     |\
    //     7 4
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // 指定要查找最近公共祖先的两个节点
    TreeNode* p = root->left;  // 节点 5
    TreeNode* q = root->left->right->right; // 节点 1

    // 实例化 Solution 类
    Solution solution;
    TreeNode* result = solution.lowestCommonAncestor(root, p, q);

    // 验证结果
    if (result) {
        std::cout << result->val << std::endl;
    } else {
        std::cout << "not found" << std::endl;
    }

    // 释放内存
    // 这里简单起见，没有实现完整的释放逻辑，实际应用中需要递归释放所有节点
    freeTree(root);
    getchar();
    return 0;
}