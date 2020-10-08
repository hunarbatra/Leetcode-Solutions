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
    //Recursive Solution
    int maxDepthRecursive(Node* root) {
        if(root == NULL) return 0;
        int depth = 0;
        for(Node* n : root->children) {
            depth = max(depth, maxDepth(n));
        }
        return depth + 1;
    }
    //Iterative Solution -> DFS
    int maxDepth(Node* root) {
        if(root == NULL) return 0;
        stack<pair<Node*,int>> stack;
        stack.push({root,1});
        int depth = 0;
        while(!stack.empty()) {
            Node* current = stack.top().first;
            int curr_depth = stack.top().second; stack.pop();
            for(Node* n : current->children) {
                stack.push({n, curr_depth+1});
            }
            depth = max(depth, curr_depth);
        }
        return depth;
    }
};