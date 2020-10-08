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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root == NULL) return {};
        vector<TreeNode*> result;
        postorder(root, to_delete, result);
        vector<TreeNode*> forest;
        if(find(to_delete.begin(), to_delete.end(), root->val) == to_delete.end()) {
             forest.push_back(root);
        }
        for(auto i : result) forest.push_back(i);
        return forest;
    }
    
    TreeNode* postorder(TreeNode* root, vector<int>& to_delete, vector<TreeNode*>& result) {
        if(root == NULL) return NULL;
        root->left = postorder(root->left, to_delete, result);
        root->right = postorder(root->right, to_delete, result);
        if(find(to_delete.begin(), to_delete.end(), root->val) != to_delete.end()) {
            if(root->left != NULL) result.push_back(root->left);
            if(root->right != NULL) result.push_back(root->right);
            return NULL;
        }
        return root;
    }
};