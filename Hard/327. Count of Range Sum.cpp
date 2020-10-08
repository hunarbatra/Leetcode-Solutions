class Solution {
private:
    class BSTNode { // Binary search tree implementation
    public:    
        long long val;
        int cnt; // how many nodes with value of "val'
        int lCnt; // how many nodes on its left subtree
        BSTNode *left;
        BSTNode *right;
        BSTNode(long long x) : val(x), cnt(1), lCnt(0), left(NULL), right(NULL) {}
    };
    
    int getBound(BSTNode *root, long long x, bool includeSelf) { // get the index of the last node that satisfy val<x (includeSelf=false) or val<=x (includeSelf = true)
        if(!root) return 0;
        if(root->val == x) return  root->lCnt + (includeSelf?root->cnt:0);
        else if(root->val > x) return getBound(root->left, x, includeSelf);
        else return root->cnt + root->lCnt + getBound(root->right, x, includeSelf);
    }
    void insert(BSTNode*& root, long long x) { // insert a node to the tree
        if(!root) root = new BSTNode(x);
        else if(root->val == x) (root->cnt)++;
        else if(root->val < x) 
            insert(root->right,x);
        else{
            ++(root->lCnt);
            insert(root->left,x);
        }
    }
    void deleteTree(BSTNode*root) { //destroy the tree
        if(!root) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
    
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) { // same idea as the multiset  version
        BSTNode *root = new BSTNode(0);
        int res = 0,  i; 
        long long left, right, sum=0;
        for(i=0; i<nums.size(); ++i) {
            sum += nums[i];
            res += getBound(root, sum-lower, true) - getBound(root, sum-upper, false);
            insert(root, sum);
        }
        deleteTree(root);
        return res;
     }
};