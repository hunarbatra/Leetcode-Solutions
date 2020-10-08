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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        return constructBST(nums, 0, nums.size()-1);
    }
    
    TreeNode* constructBST(vector<int>& nums, int left, int right) {
        if() return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = constructBST(nums, 0, mid-1);
        root->right = constructBST(nums, mid+1, 
    }
};