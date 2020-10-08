class Solution {
public:
    int rob(vector<int>& nums) {
        //let's see the edge cases first :)
        if(nums.size()==0) return 0;//if there are 0 houses, we rob $0
        if(nums.size()==1) return nums[0];//if there is one house, we rob that house and get the $
        if(nums.size()==2) return max(nums[0],nums[1]); //return the max incase of 2 houses
        
        //DP lookup array
        //int lookup[nums.size()];
        vector<int> lookup(nums.size());
        lookup[0]=nums[0]; //max profit incase of 1 house
        lookup[1]=max(nums[0],nums[1]); //max profit incase of 2 houses
        //for calculating max profit in case of 3 or more houses
        for(int i=2;i<nums.size();i++) {
            lookup[i] = max(nums[i]+lookup[i-2], lookup[i-1]);
        }
        //return lookup[nums.size()-1];
        return lookup.back();
    }
};