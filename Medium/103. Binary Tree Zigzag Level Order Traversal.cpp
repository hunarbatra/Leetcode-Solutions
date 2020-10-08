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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> result;
        int count = 0, currLevelNodes = 1;
        vector<int> path;
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()) {
            for(int i=0; i<currLevelNodes; i++) {
                TreeNode* current = queue.front(); queue.pop();
                path.push_back(current->val);
                if(current->left != NULL) queue.push(current->left);
                if(current->right != NULL) queue.push(current->right); 
            }
            if(count++ % 2 !=0) reverse(path.begin(), path.end());
            result.push_back(path);
            path.clear();
            currLevelNodes = queue.size();
        }
        return result;
    }
};