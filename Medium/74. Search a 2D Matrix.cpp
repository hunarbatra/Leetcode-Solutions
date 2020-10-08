class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        int rows = matrix.size(), cols = matrix[0].size();
      //  if(rows==0 || cols==0) return false;
       // if(target < matrix[0][0] || target > matrix[rows-1][cols-1]) return false;
        
        int left = 0, right = rows*cols-1;
        while(left <= right) {
            int mid = (left + right) / 2;
            int i = mid / cols;
            int j = mid % cols;
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
};