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
public: //Recursive
    /*int rangeSumBST1(TreeNode* root, int L, int R) {
        if(root == NULL) return 0;
        int sum = 0;
        dfs(root, sum, L, R);
        return sum;
    }
    void dfs1(TreeNode* root, int& sum, int L, int R) {
        if(root == NULL) return;
        if(root->val >= L && root->val <= R) sum += root->val;
        if(root->val > L) dfs(root->left, sum, L, R);
        if(root->val < R) dfs(root->right, sum, L, R);
    }*/
    //Iterative
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root == NULL) return 0;
        int sum = 0;
        stack<TreeNode*> stack;
        stack.push(root);
        while(!stack.empty()) {
            TreeNode* current = stack.top(); stack.pop();
            if(current->val>=L && current->val<=R) sum += current->val;
            if(current->val > L && current->left) stack.push(current->left);
            if(current->val < R && current->right) stack.push(current->right);
        }
        return sum;
    }
};