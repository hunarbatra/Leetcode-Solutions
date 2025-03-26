# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int: # DFS: O(n)
        self.res = root.val

        def dfs(root):
            if not root:
                return 0

            left_max = dfs(root.left)
            right_max = dfs(root.right)

            left_max = max(left_max, 0)
            right_max = max(right_max, 0)

            self.res = max(self.res, root.val + left_max + right_max)

            return root.val + max(left_max, right_max)

        dfs(root)
        return self.res