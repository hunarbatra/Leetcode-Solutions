class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size()==1) return 1;  
        sort(nums.begin(), nums.end()); 
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int maxlength=1, length=1;
        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i+1] == (nums[i]+1)) length++;
            else length = 1;
            maxlength = max(length, maxlength);
        }
        return maxlength;
    }
};