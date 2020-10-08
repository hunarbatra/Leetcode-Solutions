/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public: //Iterative Preorder a.k.a DFS : O(n) time and space
    Node* flattenIterative(Node* head) {
        if(!head) return nullptr;
        Node* dummy = new Node(0, nullptr, head, nullptr); //our singly LL for the result
        Node* curr, *prev = dummy;
        stack<Node*> stack;
        stack.push(head);
        while(!stack.empty()) {
            curr = stack.top(); stack.pop();
            prev->next = curr; //setting next and prev cause its a doubly LL
            curr->prev = prev;
            if(curr->next) { //right subtree
                stack.push(curr->next);
            }
            if(curr->child) { //left subtree
                stack.push(curr->child);
                curr->child = nullptr;
            }
            prev = curr;
        }
        dummy->next->prev = nullptr; //detach the dummy node from the result
        return dummy->next;
    }
    
    //Recursive
    Node* flatten(Node* head) {
        if(!head) return nullptr;
        Node* dummy = new Node(0, nullptr, head, nullptr);
        flattenDFS(dummy, head);
        dummy->next->prev = nullptr;
        return dummy->next;
    }
    Node* flattenDFS(Node* prev, Node* curr) {
        if(!curr) return prev;
        curr->prev = prev;
        prev->next = curr;
        Node* currnext = curr->next; //right sub tree
        Node* prevnext = flattenDFS(curr, curr->child); //left sub tree, go as left as possible
        curr->child = nullptr;
        return flattenDFS(prevnext, currnext);
    }
};