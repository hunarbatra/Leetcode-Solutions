class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.size() == 0) return 0;
        if(s.size() == 1) return 1;
        
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int i=0; i<n; i++) dp[i][i] = 1;
        
        for(int len=2; len<=n; len++) {
            for(int r=0; r<n-len+1; r++) {
                int c = r + len - 1;
                if(len == 2 && s[r] == s[c]) {
                    dp[r][c] = 2;
                } else if(s[r] == s[c]) {
                    dp[r][c] = 2 + dp[r+1][c-1]; //bottom diagonal + 2
                } else {
                    dp[r][c] = max(dp[r+1][c], dp[r][c-1]); //max(down, left)
                }
            }
        }
        return dp[0].back();
    }
};