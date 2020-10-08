/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
private:
    unordered_map<Node*, Node*> visited; //maps Node -> Node
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        if(visited[head]) return visited[head]; //if we've already visited it, directly return it
        Node* node = new Node(head->val, NULL, NULL); //create a clone of current head node
        visited[head] = node; //mark it as visited
        node->next = copyRandomList(head->next); //set the next ptr of the cloned node recursively
        node->random = copyRandomList(head->random); //set the random ptr of cloned node recursively
        return node;
    }
};