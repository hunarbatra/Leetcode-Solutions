class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int row = grid.size(), col = grid[0].size();
        for(int j=1; j<col; j++) grid[0][j] += grid[0][j-1]; // update the first row
        for(int i=1; i<row; i++) grid[i][0] += grid[i-1][0]; // update the first col
        for(int r=1; r<row; r++) {
            for(int c=1; c<col; c++) {
                grid[r][c] = min(grid[r][c]+grid[r-1][c], grid[r][c]+grid[r][c-1]);
            }
        }
        return grid[row-1][col-1];
    }
};