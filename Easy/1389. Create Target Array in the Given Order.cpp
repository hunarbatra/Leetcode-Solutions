class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> result;
        for(int i=0; i<nums.size(); i++) {
            //if(i==0 && index[i]!=0) result.push_back(nums[i]);
            result.emplace(result.begin()+index[i], nums[i]);
        }
        return result;
    }
};
