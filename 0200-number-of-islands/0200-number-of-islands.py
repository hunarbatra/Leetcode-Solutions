class Solution:
    def numIslands(self, grid: List[List[str]]) -> int: # recursive DFS
        directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        ROWS, COLS = len(grid), len(grid[0])
        islands = 0

        def dfs(r, c):
            if (r < 0 or c < 0 or r >= ROWS or c>= COLS or grid[r][c] == "0"):
                return 0

            grid[r][c] = "0" # mark as visited
            for dr, dc in directions:
                dfs(r + dr, c + dc)
            
            return 1

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == "1":
                    islands += dfs(r, c)

        return islands