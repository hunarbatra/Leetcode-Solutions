class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []

        def dfs(index, path, total):
            if total == target:
                res.append(path[:]) # save valid combination
                return
            if total > target or index == len(candidates):
                return

            # Option 1: Include candidates[index]
            path.append(candidates[index]) # choose
            dfs(index, path, total + candidates[index]) # explore: reuse allowed
            path.pop() # backtrack (un-choose)

            # Option 2: Skip to the next index
            dfs(index + 1, path, total)

        dfs(0, [], 0)
        return res
            