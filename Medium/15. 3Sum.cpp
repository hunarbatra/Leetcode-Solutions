class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        unordered_set<int> umap;
        for(auto i: nums) umap.insert(i);
        for(int i=0; i<nums.size()-1; i++) {
            for(int j=i+1; j<nums.size(); j++) {
                if(umap.count(0-(nums[i]+nums[j]))) {
                    results.push_back({nums[i], nums[j], 0-(nums[i]+nums[j]) });
                }
            }
        }
        unordered_map<vector<int>, int> dups;
        for(auto v : results) {
            vector<int> temp = move(v);
            sort(temp.begin(), temp.end());
            dups[temp]++;
        }
        vector<vector<int>> ans
        for(auto d : dups) {
            if(dups[d] == 1) ans.push_back(d);
        }
        return ans;
    }
};