class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size(), false); //true if nums[i] is used
        dfs(nums, result, path, used);
        //result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
    
    void dfs(vector<int>&nums, vector<vector<int>>& result, vector<int>& path, vector<bool>& used) {
        if(path.size() == nums.size()) {
            if(find(result.begin(), result.end(), path) == result.end()) {
                result.push_back(path);
            }
            return;
        }
        for(int i=0; i<nums.size(); i++) {
            if(!used[i]) {
                path.push_back(nums[i]);
                used[i] = true;
                dfs(nums, result, path, used);
                //restore for next possible number for the current position
                used[i] = false;
                path.pop_back();
            }
        }
    }
};