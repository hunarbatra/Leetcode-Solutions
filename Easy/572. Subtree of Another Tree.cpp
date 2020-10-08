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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==NULL || t==NULL) return false;
        queue<TreeNode*> queue;
        queue.push(s);
        bool result;
        while(!queue.empty()) {
            TreeNode* current = queue.front(); queue.pop();
            if(current->val == t->val) {
                result = checkSubtree(current, t);
                if(result == true) return result;
            }
            if(current->left!=NULL) queue.push(current->left);
            if(current->right!=NULL) queue.push(current->right);
        }
        return result;
    }
    
    bool checkSubtree(TreeNode* current, TreeNode* t) {
        queue<TreeNode*> queue;
        queue.push(current); queue.push(t);
        while(!queue.empty())
        {
            TreeNode *tree1 = queue.front(); queue.pop();
            TreeNode *tree2 = queue.front(); queue.pop();
            if(tree1==NULL && tree2==NULL) continue;
            if(tree1==NULL || tree2==NULL) return false;
            if(tree1->val != tree2->val) return false;
            queue.push(tree1->left);
            queue.push(tree2->left);
            queue.push(tree1->right);
            queue.push(tree2->right);
        }
        return true;  
    }
};// O(m*n)