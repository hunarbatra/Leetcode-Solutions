# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest1(self, root: Optional[TreeNode], k: int) -> int: # recursive dfs
        res = []

        def dfs(node: Optional[TreeNode]):
            if not node:
                return

            dfs(node.left)
            res.append(node.val)
            dfs(node.right)

        dfs(root)
        return res[k-1]

    def kthSmallest2(self, root: Optional[TreeNode], k: int) -> int: # recursive dfs - optimal
        self.k = k
        self.res = None

        def dfs(node: Optional[TreeNode]):
            if not node or self.res is not None:
                return

            dfs(node.left)
            self.k -= 1
            if self.k == 0:
                self.res = node.val
                return
            dfs(node.right)

        dfs(root)
        return self.res

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int: # iterative dfs
        stack = []
        curr = root

        while curr or stack:
            while curr:
                stack.append(curr)
                curr = curr.left # go as left as you can

            curr = stack.pop() # left
            k -= 1 # root
            if k == 0:
                return curr.val
            curr = curr.right # now move right
    

            