class Solution {
public:
  /*  int solve(vector<int>&nums, int l, int r) {
        //length = n
        int prev = 0, cur = 0, temp;
        for(int i=l;i<=r;i++){
            temp = max(nums[i]+prev, cur);
            prev = cur;
            cur = temp;
        }
        return cur;
    } */
    int solve(vector<int>& nums, int left, int right) {
        if(right - left == 0) return nums[left]; //if single number
        if(right - left == 1) return max(nums[left], nums[right]); //if two numbers
        vector<int> dp(right-left+1);
        dp[0] = nums[left];
        dp[1] = max(nums[left], nums[left+1]);
        for(int i = 2; i < dp.size(); i++) { //if n>=3
            dp[i] = max(nums[left+i] + dp[i-2], dp[i-1]);
        }
        return dp.back();
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        //Corner case -   
        if(n == 0)return 0;
        if(n == 1)return nums[0];
       
        //General case - 
        return max(solve(nums, 0, n-2), solve(nums, 1, n-1));
    }
};