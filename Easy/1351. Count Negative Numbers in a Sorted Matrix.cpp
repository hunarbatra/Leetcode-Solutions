class Solution {
public:
int countNegatives(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int row = grid.size(), col = grid[0].size();
        int result = 0;
        int rowBegin = 0, colEnd = col-1;
        while(rowBegin<row && colEnd>=0) {
            if(grid[rowBegin][colEnd] < 0) {
                result += (row - rowBegin);
                colEnd--;
            }
            else rowBegin++;
        }
        return result;
    }
};
