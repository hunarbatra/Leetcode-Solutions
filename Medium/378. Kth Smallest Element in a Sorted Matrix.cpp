class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {         
        //min-heap
        priority_queue<int, vector<int>, greater<int>> minheap;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[i].size(); j++) {
                minheap.push(matrix[i][j]);
            }
        }
        for(int i=0; i<k-1; i++) minheap.pop();
        return minheap.top();
    }
};