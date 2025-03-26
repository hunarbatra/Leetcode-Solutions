class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        ROWS, COLS = len(board), len(board[0])
        directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]

        def capture(r, c):
            if (r < 0 or c < 0 or r >= ROWS or c >= COLS or board[r][c] != "O"):
                return

            board[r][c] = "T" # temp visited mark

            for dr, dc in directions:
                capture(r + dr, c + dc)

        for r in range(ROWS):
            if board[r][0] == "O":
                capture(r, 0)
            if board[r][COLS - 1] == "O":
                capture(r, COLS - 1)

        for c in range(COLS):
            if board[0][c] == "O":
                capture(0, c)
            if board[ROWS - 1][c] == "O":
                capture(ROWS - 1, c)

        for r in range(ROWS):
            for c in range(COLS):
                if board[r][c] == "O":
                    board[r][c] = "X"
                elif board[r][c] == "T":
                    board[r][c] = "O"
        