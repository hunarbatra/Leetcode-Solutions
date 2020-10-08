/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree1(TreeNode* root) { //O(n) time and O(n) call stack space
        if(!root) return nullptr;
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()) {
            TreeNode* current = queue.front(); queue.pop();
            TreeNode* temp = current->left;
            current->left = current->right;
            current->right = temp;
            if(current->left) queue.push(current->left);
            if(current->right) queue.push(current->right);
        }
        return root;
    }
};