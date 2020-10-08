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
   TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       if(preorder.size()==0 || inorder.size()==0) return NULL;
       return createTree(preorder, inorder, 0, 0, inorder.size()-1);
    }
    
    TreeNode* createTree(vector<int>& preorder, vector<int>& inorder, int p_start, int i_start, int i_end){
        if(p_start>preorder.size()-1 || i_start>i_end) return NULL;
        TreeNode* root = new TreeNode(preorder[p_start]);
        int position = 0;
        for(int i=i_start; i<=i_end; i++) {
            if(inorder[i] == root->val) {
                position = i; break;
            }
        }
        root->left = createTree(preorder, inorder, p_start+1, i_start, position-1);
        root->right = createTree(preorder, inorder, p_start+position-i_start+1, position+1, i_end);
        //for the right subtree, we make p_start as p_start+position-i_start+1
        return root;
    }
};