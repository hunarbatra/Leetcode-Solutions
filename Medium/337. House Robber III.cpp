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
    int rob(TreeNode* root) {
        if(root == NULL) return 0;
        int result;
        int left_max = 0, right_max = 0;
        result = rob_dfs(root, left_max, right_max);
        return result;
    }
    int rob_dfs(TreeNode* root, int& left_max, int& right_max) {
        if(root == NULL) return 0;
        int left_c1 = 0, left_c2 = 0, right_c1 = 0, right_c2 = 0;
        left_max = rob_dfs(root->left, left_c1, left_c2);
        right_max = rob_dfs(root->right, right_c1, right_c2);
        return max(root->val+left_c1+left_c2+right_c1+right_c2, left_max+right_max);
    }
};