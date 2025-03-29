class Solution:
    def reverseDegree(self, s: str) -> int:
        ch_map = dict(zip(string.ascii_lowercase, range(26, 0, -1)))
        res = 0

        for i, ch in enumerate(s):
            res += (ch_map[ch] * (i+1))

        return res