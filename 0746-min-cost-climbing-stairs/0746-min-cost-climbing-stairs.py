class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp = [cost[0], cost[1]] + [0] * (len(cost) - 2)
        for i in range(2, len(cost)):
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]) 
        return min(dp[-1], dp[-2])