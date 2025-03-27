class TrieNode:
    def __init__(self, children: dict = {}, word: Optional[str] = None):
        self.children = {}
        self.word = None

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        root = TrieNode()

        # Build the Trie from words
        for word in words:
            node = root
            for char in word:
                if char not in node.children:
                    node.children[char] = TrieNode()
                node = node.children[char]
            node.word = word

        res = []
        ROWS, COLS = len(board), len(board[0])
        directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]

        def dfs(r, c, node):
            char = board[r][c]
            if char not in node.children:
                return

            next_node = node.children[char]
            if next_node.word:
                res.append(next_node.word)
                next_node.word = None

            # mark visited
            board[r][c] = "#"

            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if nr in range(ROWS) and nc in range(COLS) and board[nr][nc] != "#":
                    dfs(nr, nc, next_node)

            # unmark visited
            board[r][c] = char

            # Optional: prune leaf node for performance
            if not next_node.children:
                node.children.pop(char)

        # search every cell
        for r in range(ROWS):
            for c in range(COLS):
                dfs(r, c, root)

        return res