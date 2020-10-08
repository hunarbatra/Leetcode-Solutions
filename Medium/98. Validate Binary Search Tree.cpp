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
    bool isValidBST(TreeNode* root) {
        return dfs_valid(root, LONG_MIN, LONG_MAX);
    }
    
    bool dfs_valid(TreeNode* node, long low, long high) {
        if(!node) return true;
        return low<node->val && high>node->val
            && dfs_valid(node->left, low, node->val)
            && dfs_valid(node->right, node->val, high);
    }
};