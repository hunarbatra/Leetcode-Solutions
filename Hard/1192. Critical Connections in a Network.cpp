class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> adjList;
        for(auto e : connections) {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        vector<int> ids(n), low_link(n);
        vector<bool> visited(n);
        vector<vector<int>> bridges;
        int id = 0;
        dfs(0, -1, bridges, adjList, ids, low_link, visited, id);
        return bridges;
    }
    
    void dfs(int current, int parent, vector<vector<int>>& bridges, unordered_map<int,vector<int>>& adjList, 
             vector<int>& ids, vector<int>& low_link, vector<bool>& visited, int& id) {
        visited[current] = true;
        low_link[current] = ids[current] = ++id;
        //For each edge from current -> to
        for(auto& to : adjList[current]) {
            if(to == parent) continue;
            if(!visited[to]) {
                dfs(to, current, bridges, adjList, ids, low_link, visited, id);
                low_link[current] = min(low_link[current], low_link[to]);
                if(ids[current] < low_link[to]) bridges.push_back({current,to});
            } 
            else low_link[current] = min(low_link[current], ids[to]);
        }
    }
};