"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def cloneGraph1(self, node: Optional['Node']) -> Optional['Node']: # DFS O(V+E)
        if not node:
            return None
        visited = {}

        def dfs(node):
            if node in visited:
                return visited[node]

            copy = Node(node.val)
            visited[node] = copy

            for n in node.neighbors:
                copy.neighbors.append(dfs(n))

            return copy

        return dfs(node)

    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']: # BFS O(V+E)
        if not node:
            return None

        visited = {}
        visited[node] = Node(node.val)
        q = deque([node])

        while q:
            cur = q.popleft()
            for n in cur.neighbors:
                if n not in visited:
                    visited[n] = Node(n.val)
                    q.append(n)
                visited[cur].neighbors.append(visited[n])

        return visited[node]
    