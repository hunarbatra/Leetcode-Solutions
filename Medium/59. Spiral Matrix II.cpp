class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int max_n = pow(n, 2);
        int row_end = n-1, col_end = n-1, row_begin = 0, col_begin = 0;
        vector<vector<int>> result(n, vector<int>(n));
        int curr = 1;
        while(curr<=max_n && row_begin<=row_end && col_begin<=col_end) {
            for(int i=col_begin; i<=col_end; ++i) {
                result[row_begin][i] = curr++;
            }
            row_begin++;
            for(int i=row_begin; i<=row_end; ++i) {
                result[i][col_end] = curr++;
            }
            col_end--;
            if(row_begin <= row_end) {
                for(int i=col_end; i>=col_begin; --i) {
                    result[row_end][i] = curr++;
                }
                row_end--;
            }
            if(col_begin <= col_end) {
                for(int i=row_end; i>=row_begin; --i) {
                    result[i][col_begin] = curr++;
                }
                col_begin++;
            }
        }
        return result;
    }
};