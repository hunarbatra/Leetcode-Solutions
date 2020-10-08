/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        return makeInorder(root, inorder);
    }
    
    vector<int> makeInorder(TreeNode* root, vector<int>& inorder) {
        if(root == NULL) return {};
        makeInorder(root->left, inorder);
        inorder.push_back(root->val);
        makeInorder(root->right, inorder);
        return inorder;
    }
};