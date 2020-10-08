class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if(grid.empty()) return 0;
        int max_area = 0;
        for(int r=0; r<row; r++) {
            for(int c=0; c<col; c++) {
                if(grid[r][c]==1) {
                    int area = dfs(grid, r, c);
                    max_area = max(max_area, area);
                }
            }
        }
        return max_area;
    }
    
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if(i<0||j<0||i>grid.size()-1||j>grid[0].size()-1||grid[i][j]==0)
            return 0;
        grid[i][j] = 0; //mark as explored
        return (1+dfs(grid, i-1, j)+dfs(grid, i+1, j)+dfs(grid, i, j-1)+dfs(grid, i, j+1));
    }
};