class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty()) return result;
        int rowEnd = matrix.size();
        int colEnd = matrix[0].size();
        
        int rowBegin = 0;
        int colBegin = 0;
        
        while(rowBegin < rowEnd && colBegin < colEnd) {
            for(int i=colBegin; i<colEnd; i++)
                result.push_back(matrix[rowBegin][i]);
            rowBegin++; 
            
            for(int i=rowBegin; i<rowEnd; i++)
                result.push_back(matrix[i][colEnd-1]);
            colEnd--; 
            
            if(rowBegin < rowEnd) {
                for(int i=colEnd-1; i>=colBegin; i--)
                    result.push_back(matrix[rowEnd-1][i]);
                rowEnd--;
            }
            
            if(colBegin < colEnd) {
                for(int i=rowEnd-1; i>=rowBegin; i--)
                    result.push_back(matrix[i][colBegin]);
                colBegin++;
            }
        }
        return result;
    }
};