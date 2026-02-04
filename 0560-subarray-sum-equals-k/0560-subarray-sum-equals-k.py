from collections import defaultdict

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        if not len(nums):
            return 0

        seen = defaultdict(int)
        seen[0] = 1
        count, prefix = 0, 0

        for n in nums:
            prefix += n
            count += seen[prefix-k]
            seen[prefix] += 1

        return count
