# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree1(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]: # DFS: O(n^2)
        if not preorder or not inorder:
            return None

        root = TreeNode(preorder[0])
        mid = inorder.index(preorder[0])
        root.left = self.buildTree(preorder[1:mid+1], inorder[:mid])
        root.right = self.buildTree(preorder[mid+1:], inorder[mid+1:])

        return root

    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]: # DFS: O(n)
        indices = {v : i for i, v in enumerate(inorder)}
        self.pre_idx = 0
        
        def dfs(l, r):
            if l > r:
                return None

            root_val = preorder[self.pre_idx]
            self.pre_idx += 1

            root = TreeNode(root_val)
            mid = indices[root_val]
            root.left = dfs(l, mid - 1)
            root.right = dfs(mid + 1, r)

            return root

        return dfs(0, len(inorder)-1)
    