from collections import Counter

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        h = Counter(nums)
        max_count = 0
        max_el = 0

        for k, v in h.items():
            if v > max_count:
                max_count = v
                max_el = k
            
        return max_el