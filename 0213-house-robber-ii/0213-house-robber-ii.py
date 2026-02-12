class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        if len(nums) == 2:
            return max(nums)
            
        def rob_val(houses):
            prev, curr = 0, 0

            for money in houses:
                prev, curr = curr, max(prev + money, curr)

            return curr

        return max(rob_val(nums[1:]), rob_val(nums[:-1]))
