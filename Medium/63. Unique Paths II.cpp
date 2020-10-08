class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty()) return 0;
        if(obstacleGrid[0][0] == 1) return 0;
        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        vector<vector<size_t>> dp(row, vector<size_t>(col, 0));
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(obstacleGrid[i][j] == 1) continue; //do nothing as it is already 0's
                if(i==0 && j==0) dp[i][j] = 1;
                if(i>0) dp[i][j] += dp[i-1][j];
                if(j>0) dp[i][j] += dp[i][j-1];
            }
        }
        return dp[row-1][col-1];
    }
};

//Runtime = O(row * col)
//Space = O(r*c) //size of dp