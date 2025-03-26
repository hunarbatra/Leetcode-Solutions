class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        q = deque()
        fresh = 0
        time = 0

        ROWS, COLS = len(grid), len(grid[0])
        directions = [[1, 0], [-1, 0], [0, -1], [0, 1]]

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 1:
                    fresh += 1
                if grid[r][c] == 2:
                    q.append((r, c))

        while fresh > 0 and q:
            for i in range(len(q)):
                r, c = q.popleft()

                for dr, dc in directions:
                    row, col = r + dr, c + dc
                    if (row in range(ROWS) and col in range(COLS) and grid[row][col] == 1):
                        grid[row][col] = 2
                        q.append((row, col))
                        fresh -= 1

            time += 1

        return time if fresh == 0 else -1
