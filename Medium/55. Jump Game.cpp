class Solution {
public:
    bool canJump(vector<int>& nums) {
        int can_reach = 0;
        for(int pos=0; pos<=can_reach; pos++) {
            if(pos == nums.size()-1) return true;
            can_reach = max(can_reach, pos + nums[pos]);
        }
        return false;
    }
};