/* Algorithm :-
Traverse the children by their parent nodes(0,1,2,3.....n-1). 
At each moment check to see if we have visited the node's parent. 
If not, return false as we can't reach the children unless we have visited their parent. 
Also check if the child has already been visited, 
if yes return false, as we know from our observation that each node is visited only once.
During traversal, mark the nodes as visited.
*/
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> visited(n, false);
        visited[0] = true;
        for(int i=0; i<leftChild.size(); i++) {
            //If 1. parent isn't visited 
            if(!visited[i])
                return false;
            
            //2. Child has previously been visited return false
            if(leftChild[i]!=-1&&visited[leftChild[i]] || rightChild[i]!=-1&&visited[rightChild[i]])
                return false;
            
            if(leftChild[i] != -1) 
                visited[leftChild[i]] = true;
            if(rightChild[i] != -1) 
                visited[rightChild[i]] = true;
        }
        return true;
    }
};