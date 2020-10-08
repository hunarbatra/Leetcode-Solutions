class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        unordered_map<int,int> indegree; // node->indegree
        vector<int> leaves;
        for(int i=0; i<edges.size(); i++) {
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
        }
        for(int i=0; i<n; i++) {
            if(indegree[i]==1)
                leaves.push_back(i);
        }
        while(n > 2) { //we only want 1 or 2 elements in our final vector
            n = n - leaves.size();
            vector<int> newleaves;
            for(int current : leaves) {
                for(int i=0; i<edges.size(); i++) {
                    if(edges[i][0] == current) {
                        if(indegree[edges[i][1]]>1) {
                            indegree[edges[i][1]]--;
                            if(indegree[edges[i][1]] == 1) {
                                newleaves.push_back(edges[i][1]);
                            }
                        break;
                        }
                    }
                    else if(edges[i][1] == current) {
                        if(indegree[edges[i][0]]>1) {
                            indegree[edges[i][0]]--;
                            if(indegree[edges[i][0]] == 1) {
                                newleaves.push_back(edges[i][0]);
                            }
                        break;
                        }
                    }
                }
            }
            leaves = move(newleaves);
        }
        return leaves;
    }
};