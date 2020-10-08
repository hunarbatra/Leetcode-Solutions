class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return 1;
        vector<int> lookup;
        lookup.push_back(nums[0]);
        for(int i=1;i<nums.size();i++) {
            auto bs = lower_bound(lookup.begin(),lookup.end(),nums[i]); //binary search
            if(bs==lookup.end())
                lookup.push_back(nums[i]);
            else
                *bs = nums[i];
        }
        return lookup.size();
    }
};