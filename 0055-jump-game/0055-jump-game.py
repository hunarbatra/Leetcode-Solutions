class Solution:
    def canJump(self, nums: List[int]) -> bool:
        can_reach = 0
        cur_pos = 0

        while cur_pos <= can_reach:
            if cur_pos == len(nums)-1:
                return True

            can_reach = max(can_reach, cur_pos+nums[cur_pos])
            cur_pos += 1

        return False