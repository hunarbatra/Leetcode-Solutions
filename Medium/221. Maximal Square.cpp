class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int max_side = 0;
        int rows = matrix.size(), cols = matrix[0].size();
        if(rows==0 || cols==0) return 0;
        vector<vector<int>> dp(rows+1, vector<int>(cols+1, 0));
        //preprocessing (1,1) ... (row, col)
        for(int r=1; r<=rows; r++) {
            for(int c=1; c<=cols; c++) {
                if(matrix[r-1][c-1]=='1') {
                dp[r][c] = min(dp[r][c-1], min(dp[r-1][c-1], dp[r-1][c])) + 1;
                max_side = max(max_side, dp[r][c]);
                }
            }
        }
        return max_side*max_side;
    }
};