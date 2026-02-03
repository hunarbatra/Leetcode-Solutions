from collections import Counter

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        map = {}
        for i in s:
            map[i] = map.get(i, 0) + 1

        for i in t:
            map[i] = map.get(i, 0) - 1
            if map[i] < 0:
                return False

        return True


            