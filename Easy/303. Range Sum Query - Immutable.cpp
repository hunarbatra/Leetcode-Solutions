class NumArray {
private:
    vector<int> dp;
public:
    NumArray(vector<int>& nums) {
        dp.push_back(0); //size = nums.size()+1
        for(int i=1; i<=nums.size(); i++) {
            dp.push_back(nums[i-1] + dp[i-1]);
        }
    }
    
    int sumRange(int i, int j) {
        return dp[j+1] - dp[i]; //O(1) operation
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */