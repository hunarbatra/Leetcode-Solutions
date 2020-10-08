class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.empty()) return;
        int N = matrix.size(); //NxN matrix
        
        //step 1 : transpose the matrix
        for(int i=0; i<N; i++) {
            for(int j=i; j<N; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        //step 2 : swap it horizontally using 2 pointer approach
        for(int i=0; i<N; i++) {
            for(int j=0; j<N/2; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][N-1-j];
                matrix[i][N-1-j] = temp;
            }
        }
        return;
    }
};