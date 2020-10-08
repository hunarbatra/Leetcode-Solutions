class NumMatrix {
private: 
    vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
         for(int i = 0; i < matrix.size(); i++){
            dp.push_back(vector<int>());
            for(int j = 0; j < matrix[0].size(); j++)
                if(i == 0) //first row
                    if(j == 0) dp[i].push_back(matrix[0][0]); //if first col && first row....
                    else dp[i].push_back(matrix[0][j] + dp[0][j - 1]);
                else //second---last row
                    if(j == 0) dp[i].push_back(matrix[i][j] + dp[i - 1][0]); //if first col...
                    else dp[i].push_back(matrix[i][j] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1]);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int a = (row1 == 0) ? 0 : dp[row1 - 1][col2];
        int b = (col1 == 0) ? 0 : dp[row2][col1 - 1];
        int c = (row1 == 0 || col1 == 0) ? 0 : dp[row1 - 1][col1 - 1];
        return dp[row2][col2] - a - b + c;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */