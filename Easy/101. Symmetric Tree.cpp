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
  /*  bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true; //depends on interviewer tbh
        return isSymmetric(root->left,root->right);
    }
    
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if(left == NULL || right == NULL) return left==right;
        if(left->val != right->val) return false;  
        return isSymmetric(left->left,right->right) && isSymmetric(left->right,right->left);
    }*/
    
    bool isSymmetric(TreeNode* root) {
    queue<TreeNode*> queue;
    if(root==NULL) return true;
    queue.push(root); queue.push(root);
    while(!queue.empty())
    {
        TreeNode* left = queue.front(); queue.pop();
        TreeNode *right = queue.front(); queue.pop();
        if(left==NULL && right==NULL) continue;
        if(left==NULL || right==NULL) return false;
        if(left->val != right->val) return false;
        queue.push(left->left);
        queue.push(right->right);
        queue.push(left->right);
        queue.push(right->left);
    }
    return true;  
    }
};