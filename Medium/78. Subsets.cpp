class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(0, path, result, nums);
        return result;
    }
    void dfs(int index, vector<int>& path, vector<vector<int>>& result, vector<int>& nums) {
        result.push_back(path);
        for(int i=index; i<nums.size(); i++) {
            path.push_back(nums[i]);
            dfs(i+1, path, result, nums);
            path.pop_back(); //restore
        }
    }
};