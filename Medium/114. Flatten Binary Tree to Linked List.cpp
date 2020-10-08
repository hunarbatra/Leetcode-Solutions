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
private:
    TreeNode* prev = NULL;
public:
    //recursive
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
    
    //iterative
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        stack<TreeNode*> stack;
        stack.push(root);
        while(!stack.empty()) {
            TreeNode* current = stack.top(); stack.pop();
            if(current->right != NULL) stack.push(current->right);
            if(current->left != NULL) stack.push(current->left);
            if(!stack.empty()) {
                current->right = stack.top(); // e.g 1->2
            }
            current->left = NULL; //cause we need a right skewed tree
        }
        return;
    } 
};