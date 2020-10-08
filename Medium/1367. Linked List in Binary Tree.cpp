/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) return false;
        if(!head) return true;
        return findSubPath(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
    
    bool findSubPath(ListNode* head, TreeNode* root) {
        if(!head) return true; //i.e it has finished traversing the list and all nodes match
        if(!root) return false;
        return head->val==root->val && (findSubPath(head->next, root->left) || findSubPath(head->next, root->right));
    }
};
/*Time COmplexity : O(n * l) where l is the total number of nodes in list and n is total nodes in tree
*/