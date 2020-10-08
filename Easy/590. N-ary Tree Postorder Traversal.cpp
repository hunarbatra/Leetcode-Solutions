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
    vector<int> postorderRecursive(Node* root) {
        vector<int> postorder;
        helper(root, postorder);
        return postorder;
    }
    void helper(Node* node, vector<int>& postorder) {
        if(node == NULL) return;
        for(Node* n : node->children) { //left, right
            helper(n, postorder);
        }
        postorder.push_back(node->val); //root  
    }
    //Iterative
    vector<int> postorder(Node* root) { //reverse order of n-ary pre-order
        if(root == NULL) return {};
        stack<Node*> stack;
        stack.push(root);
        vector<int> postorder;
        while(!stack.empty()) {
            Node* current = stack.top(); stack.pop();
            postorder.emplace(postorder.begin(), current->val); //or use reverse at the end
            for(int i=0; i<current->children.size(); i++) {
                stack.push(current->children[i]);
            }
        }
        return postorder;
    }
};