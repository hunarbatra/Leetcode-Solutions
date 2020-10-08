class Solution {
public:
    //Idea 2 : Enumerate position for numbers i.e place 1 in pos 1,2,3 etc...
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path(nums.size());
        vector<bool> used(nums.size(), false); //true if nums[i] is used
        dfs(0, nums, result, path, used);
        return result;
    }
    
    void dfs(int cur_pos, vector<int>&nums, vector<vector<int>>& result, vector<int>& path,                          vector<bool>& used) {
        if(cur_pos == nums.size()) {
            result.push_back(path);
            return;
        }
        //enumerate possible numbers for current position
        for(int i=0; i<nums.size(); i++) {
            if(!used[i]) {
                used[i] = true;
                path[cur_pos] = nums[i];
                dfs(cur_pos+1, nums, result, path, used);
                //restore for next possible number for the current position
                //no need to restore for path because it'll be overwritten
                used[i] = false;
            }
        }
    }
    
    //Idea 1 : Enumerate number for position i.e all possibilites starting w 1,2,3 etc
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size(), false); //true if nums[i] is used
        dfs(nums, result, path, used);
        return result;
    }
    
    void dfs(vector<int>&nums, vector<vector<int>>& result, vector<int>& path, vector<bool>& used) {
        if(path.size() == nums.size()) {
            result.push_back(path);
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