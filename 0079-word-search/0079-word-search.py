class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        ROWS, COLS = len(board), len(board[0])
        directions = [[1, 0], [-1, 0], [0, -1], [0, 1]]

        def dfs(r, c, i):
            if i == len(word):
                return True
            if (r not in range(ROWS) or c not in range(COLS) or word[i] != board[r][c] or board[r][c] == "#"):
                return False

            board[r][c] = "#" # mark as visited
            
            res = False
            for dr, dc in directions:
                if dfs(r + dr, c + dc, i + 1): 
                    res = True

            board[r][c] = word[i] # put back the original letter after exploration
            return res

        for r in range(ROWS):
            for c in range(COLS):
                if dfs(r, c, 0):
                    return True
        return False