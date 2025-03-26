class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int: # recursive DFS
        directions = [[1, 0], [-1, 0], [0, -1], [0, 1]]
        ROWS, COLS = len(grid), len(grid[0])

        max_island = 0

        def dfs(r, c):
            if (r < 0 or c < 0 or r >= ROWS or c >= COLS or grid[r][c] != 1):
                return 0

            # since its a valid island, set as visited by marking it as "0", and increase cur_area count
            grid[r][c] = 0
            cur_area = 1 # 

            for dr, dc in directions:
                cur_area += dfs(r + dr, c + dc)

            return cur_area

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 1:
                    cur_area = dfs(r, c)  
                    max_island = max(max_island, cur_area)

        return max_island          

