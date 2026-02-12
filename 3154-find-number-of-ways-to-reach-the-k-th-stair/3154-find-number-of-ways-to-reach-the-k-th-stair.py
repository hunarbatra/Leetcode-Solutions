class Solution:
    def waysToReachStair(self, k: int) -> int:
        ans = 0
        for m in range(0, 31): # incremental jumps
            d = (2**m) - k # step down k times after jumping 2**m steps
            # if valid number of downs
            if 0 <= d <= m+1: # max possible downs = m+1 (i.e. in between every jump action)
                ans += math.comb(m+1, d) # combination of m+1 downs (max) and d -> choose which d positions get a down

        return ans