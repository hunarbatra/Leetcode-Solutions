#define ROTTEN 2
#define FRESH 1
#define EMPTY 0

class Solution {
public: //BFS
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        if(row == 0) return -1;
        int col = grid[0].size();
        vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<int,int>> queue;
        int total_min = 0, curr_min = -1, fresh_count = 0;
        for(int r=0; r<row; r++) {
            for(int c=0; c<col; c++) {
                if(grid[r][c] == ROTTEN) queue.push({r,c});
                else if(grid[r][c] == FRESH) fresh_count++;
            }
        }
        while(!queue.empty()) {
            int size = queue.size();
            for(int i=0; i<size; ++i) { //traverse level by level
                pair<int,int> curr_pos = queue.front(); queue.pop();
                int curr_r = curr_pos.first;
                int curr_c = curr_pos.second;
                for(auto next_pos : directions) {
                    int next_r = curr_r + next_pos[0];
                    int next_c = curr_c + next_pos[1];
                    if(next_r<0||next_c<0||next_r>row-1||next_c>col-1) continue;
                    if(grid[next_r][next_c] != FRESH) continue;
                    grid[next_r][next_c] = 2;
                    fresh_count--;
                    queue.push({next_r, next_c});
                }
            }
            curr_min++; //increments after completing a level
        }
        if(curr_min != -1) total_min = curr_min;
        return fresh_count == 0 ? total_min : -1;
    }
};