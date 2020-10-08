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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int diameter = 0; 
        dfs(root, diameter);
        return diameter;
    }
    
    int dfs(TreeNode* root, int& diameter) {
        if(!root) return 0;
        int left = dfs(root->left, diameter);
        int right = dfs(root->right, diameter);
        diameter = max(diameter, left+right); //update diameter to be either left+right or diameter
        return max(left, right) + 1; //this value goes to the calling root
        //whichever side is max+1 for the new connection
    }
};