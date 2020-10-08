/* Dijkstra Algorithm 
   ------------------
   Time : O(rc)
   Space : O(rc)
*/
class Solution {
private:
    vector<vector<int>> dist = {{0,0}, {0,1}, {0,-1}, {1,0}, {-1,0}};
public:
    int minCost(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int row = grid.size(), col = grid[0].size(), cost = 0;
        vector<vector<int>> dp(row, vector<int>(col, INT_MAX)); //we start by initialising all edges cost to MAX (dijkstra's)
        queue<pair<int,int>> q; //will store the grid indexes 
        dfs(grid, 0, 0, cost, dp, q);
        while(!q.empty()) { //we enter this only when an obstacle is seen while moving from (0,0)
            cost++; //we get stuck, so that means we need to backtrack and try another way, so we increment the cost
            int size = q.size(); //we now look for other possibilities for indexes from where we started....where we got stuck
            for(int i=0; i<size; i++) {
                pair<int,int> current = q.front(); q.pop();
                int r = current.first, c = current.second;
                for(int next=1; next<=4; next++) {
                    dfs(grid, r+dist[next][0], c+dist[next][1], cost, dp, q); //explore other directions from current index
                }
            }
        }
        return dp[row-1][col-1];
    }
    void dfs(vector<vector<int>>& grid, int r, int c, int cost, vector<vector<int>>&dp, queue<pair<int,int>>& q) {
        int row = grid.size(), col = grid[0].size();
        if(r<0 || c<0 || r>row-1 || c>col-1 || dp[r][c]!=INT_MAX) return;
        //dp[r][c] is used to avoid visiting edges whose cost we've already set - cause already set cost is the least
        
        q.push({r,c});
        dp[r][c] = cost;
        int nextIndex = grid[r][c];
        dfs(grid, r + dist[nextIndex][0], c + dist[nextIndex][1], cost, dp, q);
    }
};