class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0]=1;
        for(auto c : coins) {
            for(auto i=c; i<=amount; ++i) {
                dp[i] += dp[i-c];
            }
        }
        return dp.back();
    }
};
/*
Example : 
amount = 5; coins = [1,2,5]
i=1......i<=5 : dp[1]=dp[0]=1 ; dp[2]=1 ; dp[3]=dp[4]=dp[5]=1
i=2......i<=5 : dp[2]=2 ; dp[3]=2 ; dp[4] = 3 ; dp[5] = 3
i=5......i<=5 : dp[5] = dp[5] + dp[1] = 3 + 1 = 4
*/