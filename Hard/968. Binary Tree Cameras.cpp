
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
private:
    int res = 0;
public:
    int minCameraCover(TreeNode* root) {
        return (dfs(root) < 1 ? 1 : 0) + res;//check if root is covered by its children or not
        //if dfs(root) > 1 -> it is covered : else return res + 1
    }

    int dfs(TreeNode* root) {
        if (!root) return 2; 
        int left = dfs(root->left);
        int right = right = dfs(root->right);
        if (left == 0 || right == 0) { //if leaf -> place camera on its parent
            res++;
            return 1; // -> parent ad its children are now covered
        }
        return left == 1 || right == 1 ? 2 : 0; // if left||right==1 -> it is a covered node, so return 2
        //if its not a covered node i.e its left/right child is not 1 aka a parent OR is 2 -- return 0;
    }
};