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
    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return nullptr;
        vector<int> nums;
        makeInorder(root, nums);
        return makeBST(nums, 0, nums.size()-1);
    }
    
    void makeInorder(TreeNode *root, vector<int>& nums) {
        if(!root) return;
        makeInorder(root->left, nums);
        nums.push_back(root->val);
        makeInorder(root->right, nums);
    }
    
    TreeNode* makeBST(vector<int>& nums, int left, int right) {
        if(left>right) return nullptr;
        int mid = left+(right-left)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = makeBST(nums, left, mid-1);
        root->right = makeBST(nums, mid+1, right);
        return root;
    }
};
