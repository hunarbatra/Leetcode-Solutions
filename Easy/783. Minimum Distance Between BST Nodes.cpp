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
    int minDiffInBST(TreeNode* root) {
        if(root == NULL) return 0;
        int min_dist = INT_MAX;
        vector<int> inorder;
        makeInorder(root, inorder, min_dist);
        return min_dist;
    }
    
    void makeInorder(TreeNode* root, vector<int>& inorder, int& min_dist) {
        if(root == NULL) return;
        makeInorder(root->left, inorder, min_dist);
        if(inorder.size() >= 1)
            min_dist = min(min_dist, root->val - inorder.back());
        inorder.push_back(root->val);
        makeInorder(root->right, inorder, min_dist);
    }
};