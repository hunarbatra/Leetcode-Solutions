class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1 || nums[0] == 0) return 0;
        
        int can_reach = nums[0], jumps = 1, curr_end = nums[0];
        
        for(int pos=1; pos<nums.size(); pos++) {
            if(pos == nums.size()-1) return jumps;
            can_reach = max(can_reach, pos + nums[pos]);
            if(pos == curr_end) {
                jumps++;
                curr_end = can_reach;
            }
        }
        return jumps;
    }
};