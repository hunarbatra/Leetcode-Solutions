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
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL) return {};
        vector<vector<int>> result;
        queue<Node*> queue;
        queue.push(root);
        while(!queue.empty()) {
            int level_size = queue.size();
            vector<int> curr_level;
            for(int i=0; i<level_size; i++) {
                Node* current = queue.front(); queue.pop();
                curr_level.push_back(current->val);
                for(Node* n : current->children) {
                    queue.push(n);
                }
            }
            if(!curr_level.empty()) result.push_back(curr_level);
        }
        return result;
    }
};