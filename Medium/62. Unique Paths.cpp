class Solution {
public:
    int uniquePaths(int r, int c) {
        vector<vector<int>> dp(r, vector<int>(c));
        for(int i=0; i<r; i++) dp[i][0] = 1;
        for(int i=0; i<c; i++) dp[0][i] = 1;
        for(int i=1; i<r; i++) {
            for(int j=1; j<c; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1]; //sum of top & left
            }
        }
        return dp[r-1][c-1];
    }
};