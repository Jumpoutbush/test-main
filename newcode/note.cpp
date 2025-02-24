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
    void insert(TreeNode* &root, vector<int>& nums, int left, int right) {
        if(left > right)
            return;
        int mid = (left + right) / 2;
        if(root == nullptr){
            root = new TreeNode(nums[mid]);
        }
        insert(root->left, nums, left, mid - 1);
        insert(root->right, nums, mid + 1, right);
        return;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = nullptr;
        insert(root, nums, 0, nums.size() - 1);
        return root;
    }
};

int main()
{
    vector<int> v{-10, -3, 0, 5, 9};
    Solution sol;
    TreeNode* root = sol.sortedArrayToBST(v);
    function<void(TreeNode*)> midOrder = [&](TreeNode* node) mutable {
        if(node == nullptr){
            return;
        }
        midOrder(node->left);
        cout << node->val << " ";
        midOrder(node->right);
    };
    midOrder(root);
    getchar();
    return 0;
}