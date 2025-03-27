class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
    
        def dfs(index, path):
            res.append(path[:]) # add a copy fo teh current subset
            for i in range(index, len(nums)):
                path.append(nums[i]) # choose
                dfs(i + 1, path) # explore
                path.pop() # backtrack (un-choose)

        dfs(0, [])
        return res