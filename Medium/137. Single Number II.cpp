class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        int ans;
        sort(nums.begin(), nums.end()); //use a linear sort like radix or count for O(n)
        for(int i=0; i<nums.size()-2; i++) {
            if(nums[i+2]==nums[i]) i=i+2;
            else return nums[i];
        }
        return nums.back();
    }
};  