class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int overall_max = INT_MIN;
        for(int r=0; r<matrix.size(); r++) {
            int curr_min = INT_MAX;
            int curr_col = -1;
            for(int c=0; c<matrix[0].size(); c++) {
                if(matrix[r][c] < curr_min) {
                    curr_min = matrix[r][c];
                    curr_col = c;
                }
            }
            bool check_col = true;
            for(int i=0; i<matrix.size(); i++) {
                if(curr_col >= 0 && matrix[i][curr_col] > curr_min) check_col = false;
            }
            if(check_col && curr_min!=INT_MAX) overall_max = max(overall_max, curr_min);
        }
        if(overall_max == INT_MIN) return {};
        return {overall_max};
    }
};