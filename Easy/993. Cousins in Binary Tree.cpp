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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 0);
        int parent = -1;

        while (!q.empty()) {
            int size = q.size();
            for (int i=0;i<size;i++) {
                TreeNode* node = q.front().first;
                int value = q.front().second;

                if (node->val == x || node->val == y) {
                    if (parent != -1) {
                        if (parent == value)
                            return false;
                        else
                            return true;
                    }

                    parent = value;
                }

                q.pop();
                if (node->left) q.emplace(node->left, node->val);
                if (node->right) q.emplace(node->right, node->val);
            }

            if (parent != -1) {
                return false;
            }
        }

        return false;
    }
};

