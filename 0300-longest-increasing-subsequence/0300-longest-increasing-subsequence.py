class Solution:
    def lengthOfLISDP(self, nums: List[int]) -> int: # DP
        n = len(nums)
        dp = [1] * n # every element is at least a sequence of length 1

        for i in range(n):
            for j in range(i):
                if nums[j] < nums[i]:
                    dp[i] = max(dp[i], dp[j] + 1)

        return max(dp)

    def lengthOfLIS(self, nums: List[int]) -> int: # Binary Search
        sub = []

        for num in nums:
            i = bisect_left(sub, num)
            if i == len(sub):
                sub.append(num)
            else:
                sub[i] = num

        return len(sub)
    