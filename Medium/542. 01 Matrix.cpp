class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row == 0) return matrix;
        int col = matrix[0].size();
        vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<int,int>> queue;
        int zero_count = 0;
        for(int r=0; r<row; ++r) {
            for(int c=0; c<col; ++c) {
                if(matrix[r][c]) matrix[r][c] = INT_MAX;
                else queue.push({r,c});
            }
        }
        while(!queue.empty()) {
            pair<int,int> curr_pos = queue.front(); queue.pop();
            int curr_r = curr_pos.first;
            int curr_c = curr_pos.second;
            int min_move = INT_MAX;
            for(auto next_pos : directions) {
                int next_r = curr_r + next_pos[0];
                int next_c = curr_c + next_pos[1];
                if(next_r<0||next_c<0||next_r>row-1||next_c>col-1) continue;
                if(matrix[next_r][next_c] > matrix[curr_r][curr_c]) {
                    matrix[next_r][next_c] = matrix[curr_r][curr_c] + 1;
                    queue.push({next_r, next_c});
                }
            }
        }
        return matrix;
    }
};