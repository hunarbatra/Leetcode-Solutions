# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root): # iterative
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return "N"

        res = []
        q = deque([root])

        while q:
            node = q.popleft()
            if not node:
                res.append("N")
            else:
                res.append(str(node.val))
                q.append(node.left)
                q.append(node.right)

        return ",".join(res)

    def deserialize(self, data): # iterative
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        vals = data.split(",")

        if vals[0] == "N":
            return None

        root = TreeNode(int(vals[0]))
        q = deque([root])

        index = 1

        while q:
            node = q.popleft()
            if vals[index] != "N":
                node.left = TreeNode(int(vals[index]))
                q.append(node.left)
            index += 1
            if vals[index] != "N":
                node.right = TreeNode(int(vals[index]))
                q.append(node.right)
            index += 1

        return root

    def serialize(self, root): # recursive
        res = []

        def dfs(node):
            if not node:
                res.append("N")
                return
            
            res.append(str(node.val))
            dfs(node.left)
            dfs(node.right)

        dfs(root)
        return ",".join(res)

    def deserialize(self, data: str) -> Optional[TreeNode]: # recursive
        vals = data.split(",")
        self.i = 0

        def dfs():
            if vals[self.i] == "N":
                self.i += 1
                return None
            
            node = TreeNode(int(vals[self.i]))
            self.i += 1
            node.left = dfs()
            node.right = dfs()

            return node

        return dfs()
        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))