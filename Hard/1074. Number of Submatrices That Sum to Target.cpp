class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int count = 0;
        for(int L=0; L<cols; L++) {
            vector<int> running_rows(rows,0);
            for(int R=L; R<cols; R++) { //calculate running rows sum
                for(int i=0; i<rows; i++) running_rows[i] += matrix[i][R];
                int sum = 0;
                unordered_map<int, int> visited;
                for(int i=0; i<rows; i++) {
                    visited[sum]++;
                    sum = sum + running_rows[i];
                    if(visited[sum - target]) 
                        count += visited[sum - target];
                }
            }
        }
        return count;
    }
};