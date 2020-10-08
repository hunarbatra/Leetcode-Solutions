class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, path, result);
        return result;
    }
    
    void dfs(vector<int>& candidates, int target, int index, vector<int>& path, vector<vector<int>>& result){
        if(target == 0) { //our goal
            if(find(result.begin(), result.end(), path) == result.end()) {
                result.push_back(path); //or use a set for result to remove duplicates, set<vector<int>> res;
            }
            return;
        } //our choice
        for(int i=index; i<candidates.size(); i++) {
            if(candidates[i] > target) return; //constraint
            path.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], i+1, path, result);
            path.pop_back(); //restore
        }
    }
};

/*
Time Complexity :
O( C(n,1) + C(n,2) + .... + C(n,p) )
Space Complexity :
O(path + recursion stack) = O(p)
*/
