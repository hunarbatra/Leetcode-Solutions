class Solution {
public:
     bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        int rows = matrix.size(), cols = matrix[0].size();
        if(rows==0 || cols==0) return false;
        if(target < matrix[0][0] || target > matrix[rows-1][cols-1]) return false;
        
        int rowBegin = 0, colEnd = cols-1;
        while(rowBegin<rows && colEnd>=0) {
            if(matrix[rowBegin][colEnd]==target) return true;
            else if(matrix[rowBegin][colEnd]>target) colEnd--;
            else if(matrix[rowBegin][colEnd]<target) rowBegin++;
        }
        return false;
     }
};
    
    
   bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        int rows = matrix.size(), cols = matrix[0].size();
        if(rows==0 || cols==0) return false;
        if(target < matrix[0][0] || target > matrix[rows-1][cols-1]) return false;
        while(target>matrix[0][0] && target<matrix[0][cols-1]) {
            cols--;
        }  
        while(target>matrix[0][0] && target<matrix[rows-1][0]) {
            rows--;
        }
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) 
                if(matrix[i][j]==target) return true;
        }
        return false;
    }
};
   
     
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        int rows = matrix.size(), cols = matrix[0].size();
        if(rows==0 || cols==0) return false;
        if(target < matrix[0][0] || target > matrix[rows-1][cols-1]) return false;
        for(int i=0; i<rows; ++i) { //edge case 
             for(int j=0; j<cols; ++j) {
                if(matrix[i][j]==target) return true;
                else if(matrix[i][j]>target) break; //if i,j is greater than target then break from this col
                                                    //and advance to check the next row to find the target
            }
        }
        return false;
    }
};