class Solution:
    def climbStairs(self, n: int) -> int:
        lookup = [0] * (n+1)
        lookup[0] = 1
        lookup[1] = 1

        for i in range(2, n+1):
            lookup[i] = lookup[i-1] + lookup[i-2]

        return lookup[-1]
