class Solution {
public:
    int minDistance(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        for(int r=0; r<=text1.size(); r++) {
            for(int c=0; c<=text2.size(); c++) {
                if(r==0 || c==0) dp[r][c] = r+c;
                else if(text1[r-1] == text2[c-1]) dp[r][c] = dp[r-1][c-1];
                else dp[r][c] = min(dp[r-1][c], dp[r][c-1]) + 1;
            }
        }
        return dp[text1.size()][text2.size()];
    }
};