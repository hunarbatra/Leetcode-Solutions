/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> stack;
public:
    BSTIterator(TreeNode* root) {
        LeftInorder(root);
    }
    
    void LeftInorder(TreeNode* root) {
        while(root) {
            stack.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* curr = stack.top(); stack.pop();
        if(curr->right) LeftInorder(curr->right);
        return curr->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return stack.size() > 0;
    }
};


class BSTIterator1 { //Solution #1 -> O(1) for hasNext() & next() and Space -> O(N) [we want space to be O(h)]
private:
    vector<int> inorder;
    int index = 0;
public:
    BSTIterator1(TreeNode* root) {
        makeInorder(inorder, root);
    }
    
    void makeInorder(vector<int>& inorder, TreeNode* root) {
        if(!root) return;
        makeInorder(inorder, root->left);
        inorder.push_back(root->val);
        makeInorder(inorder, root->right);
    }
    
    /** @return the next smallest number */
    int next() {
        if(index >= inorder.size()) return 0;
        int next = inorder[index++];
        return next;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return index >= inorder.size() ? false : true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */