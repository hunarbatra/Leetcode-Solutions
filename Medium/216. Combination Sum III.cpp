class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<vector<int>> result;
        vector<int> path;
        vector<int> candidates({1,2,3,4,5,6,7,8,9});
        dfs(candidates, target, 0, path, result, k);
        return result;
    }
    
    void dfs(vector<int>& candidates, int target, int index, vector<int>& path, vector<vector<int>>& result, int k){
        if(target == 0) { //our goal
            if(find(result.begin(), result.end(), path) == result.end() && path.size()==k) {
                result.push_back(path); //or use a set for result to remove duplicates, set<vector<int>> res;
            }
            return;
        } //our choice
        for(int i=index; i<candidates.size(); i++) {
            if(candidates[i] > target) return; //constraint
            path.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], i+1, path, result, k);
            path.pop_back(); //restore
        }
    }
};