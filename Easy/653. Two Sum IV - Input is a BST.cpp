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
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> exists;
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()) {
            int size = queue.size();
            while(size--) {
                TreeNode* curr = queue.front(); queue.pop();
                if(exists.count(k - curr->val)) return true;
                exists.insert(curr->val);
                
                if(curr->left) queue.push(curr->left);
                if(curr->right) queue.push(curr->right);
            }
        }
        return false;
    }
};