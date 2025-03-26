import bisect

class Solution:
    def search1(self, nums: List[int], target: int) -> int: # using built-in function
        index = bisect.bisect_left(nums, target)

        if index < len(nums) and nums[index] == target:
            return index
        return -1

    def search(self, nums: List[int], target: int) -> int: # iterative binary search
        l, r = 0, len(nums) - 1

        while l <= r:
            m = (l + r) // 2

            if nums[m] == target:
                return m
            elif nums[m] < target:
                l = m + 1
            else:
                r = m - 1

        return -1