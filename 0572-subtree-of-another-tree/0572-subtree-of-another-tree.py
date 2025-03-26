# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree1(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool: # iterative BFS + recursive DFS O(m*n)
        q = deque()

        if root:
            q.append(root)

        while q:
            node = q.popleft()
            
            if node.val == subRoot.val:
                cur_res = self.isSameTree(node, subRoot)
                if cur_res:
                    return cur_res

            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)

        return False

    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool: # Recursive DFS + DFS O(m*n)
        if not subRoot:
            return True
        if not root:
            return False

        if self.isSameTree(root, subRoot):
            return True

        return (
            self.isSubtree(root.left, subRoot) or
            self.isSubtree(root.right, subRoot)
        )

    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if not p and not q:
            return True

        if p and q and p.val == q.val:
            return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
        else:
            return False
