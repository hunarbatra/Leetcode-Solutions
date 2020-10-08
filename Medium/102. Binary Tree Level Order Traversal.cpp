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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> result; 
        vector<int> row; queue<TreeNode*> queue;
        queue.push(root); 
        result.push_back({root->val});
        int count = queue.size();
        while(!queue.empty()) {
            TreeNode* current = queue.front(); queue.pop();
            if(current->left != NULL) {
                queue.push(current->left);
                row.push_back(current->left->val);
            }
            if(current->right != NULL) {
                queue.push(current->right); 
                row.push_back(current->right->val);
            }
            if(--count == 0) {
                result.push_back(row); row.clear(); 
                count = queue.size();
            }
        }
        result.pop_back();
        return result;
    }
};