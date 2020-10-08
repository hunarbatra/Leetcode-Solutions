class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        if(rows == 0 || cols == 0) return 0;
        
        vector<vector<int>> dp(rows, vector<int>(cols,0));
        
        int longest=1;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(dp[i][j] == 0) {
                    dfs(matrix, i, j, dp, INT_MIN);
                    longest = max(longest, dp[i][j]);
                }
            }
        }
        return longest;
    }
    
    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp, int prev) {
        if(i<0 || j<0 || i>matrix.size()-1 || j>matrix[0].size()-1 || matrix[i][j]<=prev) return 0;
        
        if(dp[i][j]!=0) return dp[i][j]; //if we've already calculated the longest incr path for i,j
        
        int left = dfs(matrix, i, j-1, dp, matrix[i][j]);
        int right = dfs(matrix, i, j+1, dp, matrix[i][j]);
        int up = dfs(matrix, i-1, j, dp, matrix[i][j]);
        int down = dfs(matrix, i+1, j, dp, matrix[i][j]);
        dp[i][j] = max(left, max(right, max(up, down))) + 1; //1 is added for every correct neighbour
        return dp[i][j];
    }
};