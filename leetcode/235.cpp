#include <iostream>

// 定义二叉搜索树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 从根节点开始遍历
        while (root) {
            if (root->val > p->val && root->val > q->val) {
                // p 和 q 都在左子树
                root = root->left;
            } else if (root->val < p->val && root->val < q->val) {
                // p 和 q 都在右子树
                root = root->right;
            } else {
                // 当前节点就是最近公共祖先
                return root;
            }
        }
        return nullptr;
    }
};

// 辅助函数：插入节点到二叉搜索树
TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void freeTree(TreeNode* root) {
    delete root;
    freeTree(root->left);
}

int main() {
    // 创建一个简单的二叉搜索树
    TreeNode* root = nullptr;
    int values[] = {6, 2, 8, 0, 4, 7, 9, 3, 5};
    for (int val : values) {
        root = insert(root, val);
    }

    // 指定要查找最近公共祖先的两个节点
    TreeNode* p = root->left;  // 节点 2
    TreeNode* q = root->right->right; // 节点 8

    // 实例化 Solution 类
    Solution solution;
    TreeNode* result = solution.lowestCommonAncestor(root, p, q);

    // 验证结果
    if (result) {
        std::cout << "最近公共祖先节点的值是: " << result->val << std::endl;
    } else {
        std::cout << "未找到最近公共祖先节点。" << std::endl;
    }

    // 释放内存（简单起见，未实现完整的释放逻辑）
    // 实际应用中需要递归释放所有节点
    freeTree(root);
    getchar();
    return 0;
}