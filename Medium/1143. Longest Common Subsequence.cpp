class Solution {
public:
    int longestCommonSubsequence1(string text1, string text2) {
        if(text1.size() == 0 || text2.size() == 0) return 0;
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        for(int r=1; r<=text1.size(); r++) {
            for(int c=1; c<=text2.size(); c++) {
                //1. If its a match
                if(text1[r-1] == text2[c-1]) {
                    dp[r][c] = dp[r-1][c-1] + 1;
                } else { //
                    dp[r][c] = max(dp[r-1][c], dp[r][c-1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
/*
Memory Optimization
You may notice that we are only looking one row up in the solution above. So, we just need to store two rows.
*/
int longestCommonSubsequence(string &a, string &b) {
  if (a.size() < b.size()) return longestCommonSubsequence(b, a);
  vector<vector<short>> m(2, vector<short>(b.size() + 1));
  for (auto i = 1; i <= a.size(); ++i)
    for (auto j = 1; j <= b.size(); ++j)
      if (a[i - 1] == b[j - 1]) m[i % 2][j] = m[(i -1) % 2][j - 1] + 1;
      else m[i % 2][j] = max(m[(i - 1) % 2][j], m[i % 2][j - 1]);
  return m[a.size() % 2][b.size()];
}
};
/*Complexity Analysis
Runtime: O(nm), where n and m are the string sizes.
Memory: O(min(n,m)). */
