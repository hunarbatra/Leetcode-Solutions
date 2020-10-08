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
private:
    vector<int> vec;
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        stack<TreeNode*> stack;
        while(!stack.empty() || root) {
            while(root) {
                stack.push(root);
                root = root -> left;
            }
            root = stack.top(); stack.pop();
            if(!--k) return root->val;
            root = root -> right;
        }
        return 0;
    }
};