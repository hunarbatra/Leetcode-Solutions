class Solution {
public:
    //Approach 2 --- compare with top-left neighbour //O(m*n) && space = O(1)
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int r=1; r<matrix.size(); r++) {
            for(int c=1; c<matrix[0].size(); c++) {
                if(matrix[r-1][c-1] != matrix[r][c]) return false;
            }
        }
        return true;
    }
};
    
/*    //O(mxn) --- Approach 1 Space = O(n)
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty()) return false;
        int rows = matrix.size(), cols = matrix[0].size();
        unordered_map<int,int> group;
        for(int r=0; r<rows; r++) {
            for(int c=0; c<cols; c++) {
                if(!group[r-c])
                    group[r-c] = matrix[r][c];
                else if(group[r-c]!=matrix[r][c]) return false;
            }
        }
        return true;
    }
}; */

/*
[0,0  0,1  0,2, 0,3]
[1,0  1,1  1,2  1,3]
[2,0  2,1  2,2  2,3]
[3,0  3,1  3,2  3,3]

row - column
[0 -1 -2 -3]
[1  0 -1 -2]
[2  1  0 -1]
[3  2  1  0] */