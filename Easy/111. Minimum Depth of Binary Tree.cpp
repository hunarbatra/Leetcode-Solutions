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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if(left == 0 || right == 0) //leaf
            return max(left,right)+1;
        return min(left,right)+1;
    }
    
    int minDepthIter(TreeNode* root) {
        if(root == NULL) return 0;
        stack<pair<TreeNode*,int>> stack;
        stack.push({root,1});
        int result = INT_MAX;
        while(!stack.empty()) {
            TreeNode* current = stack.top().first; 
            int min_depth = stack.top().second; stack.pop();
            if(current->right) stack.push({current->right, min_depth+1});
            if(current->left) stack.push({current->left, min_depth+1});
            if(!current->left && !current->right) result = min(result, min_depth); //leaf
        }
        return result;
    }
};