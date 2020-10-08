class Solution {
public:
    int numSquares(int n) {
        if(n<=0) return 0;
        vector<int> dp(n+1, n);
        dp[0] = 0;
        for(int num=1; num<=n; num++) {
            for(int sq=1; sq*sq<=num; sq++) {
                dp[num] = min(dp[num], dp[num - (sq * sq)] + 1);
            }
        }
        return dp.back();
    }
};