/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    //Recursive
    vector<int> preorder(Node* root) {
        vector<int> preorder;
        helper(root, preorder);
        return preorder;
    }
    void helper(Node* node, vector<int>& preorder) {
        if(node == NULL) return;
        preorder.push_back(node->val);
        for(Node* n : node->children) {
            helper(n, preorder);
        }
    }
    //Iterative
    vector<int> preorderIteractive(Node* root) {
        if(root == NULL) return {};
        vector<int> preorder;
        stack<Node*> stack;
        stack.push(root);
        while(!stack.empty()) {
            Node* current = stack.top(); stack.pop();
            preorder.push_back(current->val);
            for(int i=current->children.size()-1; i>=0; i--) {
                stack.push(current->children[i]);
            }
        }
        return preorder;
    }
};