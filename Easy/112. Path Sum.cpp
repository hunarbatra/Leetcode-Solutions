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
    //Recursive -> O(n) RT and O(n) call stack space
     bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        int new_sum = sum - root->val;
        if(!root->left && !root->right) return new_sum==0;
        return hasPathSum(root->left, new_sum) || hasPathSum(root->right, new_sum);
    }
    //Iterative -> O(n) RT and O(n) stack space
    bool hasPathSumIter(TreeNode* root, int sum) {
        if(root == NULL) return false;
        stack<pair<TreeNode*,int>> stack;
        stack.push({root, root->val});
        while(!stack.empty()) {
            TreeNode* current = stack.top().first; 
            int total_sum = stack.top().second; stack.pop();
            if(current->right) stack.push({current->right, total_sum+current->right->val});
            if(current->left) stack.push({current->left, total_sum+current->left->val});
            if(!current->right && !current->left && total_sum==sum) { //if its a leaf
                return true; //and total sum is found
            }
        }
        return false;
    } 
}; 