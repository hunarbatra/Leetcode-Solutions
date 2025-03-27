class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        if len(nums) == 2:
            return max(nums)

        def rob_linear(houses):
            prev, curr = 0, 0
            for money in houses:
                new_prev = curr
                curr = max(curr, prev + money)
                prev = new_prev 
                # prev, curr = curr, max(curr, prev + money) # simply do this instead

            return curr

        return max(rob_linear(nums[1:]), rob_linear(nums[:-1]))