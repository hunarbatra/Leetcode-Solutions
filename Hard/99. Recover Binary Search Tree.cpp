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
    TreeNode* first_num = nullptr;
    TreeNode* second_num = nullptr;
    TreeNode* prev_num = new TreeNode(INT_MIN);
public:
    void recoverTree(TreeNode* root) {
        if(!root) return;
        traverse(root);
        if(first_num && second_num) swap(first_num->val, second_num->val);
        return;
    }
    
    void traverse(TreeNode* root) {
        if(!root) return;
        traverse(root->left);
        if(!first_num && prev_num->val > root->val) {
            first_num = prev_num;
        }
        if(first_num && prev_num->val > root->val) {
            second_num = root;
        }
        prev_num = root;
        traverse(root->right);
    }
};