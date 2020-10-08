class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, path, result);
        return result;
     }
    
    void dfs(vector<int>& candidates, int target, int index, vector<int>& path, vector<vector<int>>& result) {
        //goal
        if(target == 0) {
            result.push_back(path);
            return;
        }
        //our choice
        for(int i=index; i<candidates.size(); i++) {
            if(candidates[i] > target) return; //i.e backtrack //our constraint
            path.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], i, path, result);
            path.pop_back(); //restore
        }
    }
};