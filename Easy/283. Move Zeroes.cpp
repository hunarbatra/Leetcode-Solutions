class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i=0, non_zero_ctr = 0; i<nums.size(); i++) if(nums[i]) swap(nums[i], nums[non_zero_ctr++]);
    }
};