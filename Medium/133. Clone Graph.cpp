/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
private:
    unordered_map<Node*, Node*> hash;
public:
    Node* cloneGraphBFS(Node* node) {
        if(!node) return NULL;
        
        queue<Node*> node_queue; //make a queue
        node_queue.push(node); //push starting element of graph into it
        hash[node] = new Node(node->val); //initialize list with starting element of graph w its val
        
        //BFS 
        while(!node_queue.empty()) {
            //Summary of the algorithm :
            //while queue is not empty, take the first element of queue, find its neighbours
            //if its neighbours are not present in adjacency list, create an entry for them
            //if the neighbour is present in the adjacency list, then push it back to the
            //neighbours list of that particular node in order to make a connection
            //queue stores the nodes
            //hashmap stores the connections b/w the nodes i.e the path/edge
            //hashmap kinda acts like an adjacency list here or like an explored nodes checker
            Node* temp = node_queue.front();
            node_queue.pop();
            
            for(Node* n : temp->neighbors) {
                if(hash.find(n) == hash.end()) {
                    hash[n] = new Node(n->val);
                    node_queue.push(n);
                }
                hash[temp]->neighbors.push_back(hash[n]); 
            }
        }
        return hash[node];
    }
    
    //DFS
    //Algorithm :
    //If hashmap doesnt consist of node (which it won't for the first time it sees a new node)
    //so , add it to hashmap w its val
    //for all the neighbours of A, add that to hashmap, then add neighbours of B recursively
    //then neighbours of B's next until it reaches a dead end, then it backtracks 
    //and visits rest of the unexplored nodes in the same manner
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        if(hash.find(node) == hash.end()) {
            hash[node] = new Node(node->val);
            for(Node* n : node->neighbors) {
                hash[node]->neighbors.push_back(cloneGraph(n));            
            }
        }
        return hash[node];
    }  
};