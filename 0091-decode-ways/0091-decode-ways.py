class Solution:
    def numDecodings(self, s: str) -> int:
        if not s or s[0] == "0":
            return 0

        n = len(s)
        dp = [0] * (n+1)
        dp[0] = 1
        dp[1] = 1 # first char is guaranteed not '0'

        for i in range(2, n+1):
            # one digit decode (s[i-1])
            if s[i-1] != "0":
                dp[i] += dp[i-1]

            # two digit decode (s[i-2:i])
            if 10 <= int(s[i-2:i]) <= 26:
                dp[i] += dp[i-2]

        return dp[-1]