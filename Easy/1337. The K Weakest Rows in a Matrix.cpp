typedef pair<int,int> pi;
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int row = mat.size();
        int col = mat[0].size();
        if(mat.empty()) return {};
        if(k > row) return {};
        if(row < 1) return {};
        vector<int> result;
        priority_queue<pi, vector<pi>, greater<pi>> minheap;
        for(int r=0; r<row; r++) {
            int count = 0;
            for(int c=0; c<col; c++) {
                if(mat[r][c]==1) {
                    count++;
                }
            }
            minheap.push({count, r});
        }
        while(k-- != 0) {
            pair<int,int> current = minheap.top(); minheap.pop();
            result.push_back(current.second);
        }
        return result;
    }
};