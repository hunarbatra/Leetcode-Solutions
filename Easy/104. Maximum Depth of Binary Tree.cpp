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
    int maxDepth1(TreeNode* root) { // Time : O(n)
        if(!root) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1; 
    }
    
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int result = 0;
        queue<tuple<TreeNode*, int>> q;
        q.push({root, 1});
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto [node, depth] = q.front(); q.pop();
                result = max(result, depth);
                if(node->left) q.push({node->left, depth+1});
                if(node->right) q.push({node->right, depth+1});
            }
        }
        return result;
    }
    
    int maxDepth3(TreeNode* root) { // level by level 
        if(!root) return 0;
        int result = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                TreeNode* current = q.front(); q.pop();
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
            result++;
        }
        return result;
    }
};