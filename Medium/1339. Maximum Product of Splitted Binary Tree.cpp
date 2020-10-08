/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static int MOD=1e9+7;
class Solution {
private:
    long long totalSum = 0, result = 0;
public:
    int maxProduct(TreeNode* root) {
        inorder(root);
        checkMax(root);
        return result%MOD;
    }
    
    void inorder(TreeNode* root) {
        if(root == NULL) return;
        inorder(root->left);
        totalSum += root->val;
        inorder(root->right);        
    }
    
    int checkMax(TreeNode* root) {
        if(root==NULL) return 0;
        int leftSum = checkMax(root->left); int rightSum = checkMax(root->right);
        result = max({result, (totalSum-leftSum)*leftSum, (totalSum-rightSum)*rightSum});
        return max(root->val+leftSum+rightSum, root->val+max(leftSum,rightSum));
    }
};