#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Function to create a new tree node
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

// The rightSideView function
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;
    queue<TreeNode*> q;
    q.push(root);
    bool flag;
    while(!q.empty()){
        flag = true;
        int n = q.size();
        for(int i = 0; i < n; i++){
            TreeNode* cur = q.front();
            q.pop();
            if(flag){
                ans.push_back(cur->val);
                flag = false;
            }
            
            if(cur->right){
                q.push(cur->right);
            }
            if(cur->left){
                q.push(cur->left);
            }
        }
    }
    return ans;
}

// Main function to test the rightSideView function
int main() {
    // Create a binary tree
    TreeNode* root = newNode(1);
    root->right = newNode(3);
    root->left = newNode(2);
    root->left->right = newNode(5);
    root->left->left = newNode(4);
    root->right->right = newNode(7);
    root->right->right->left = newNode(6);

    // Get the right side view of the binary tree
    vector<int> result = rightSideView(root);

    // Print the result
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}
