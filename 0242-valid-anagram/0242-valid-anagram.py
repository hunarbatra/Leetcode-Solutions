from collections import Counter

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        # count = {}

        # for ch in s:
            # count[ch] = count.get(ch, 0) + 1

        count = Counter(s)
        for ch in t:
            # count[ch] = count.get(ch, 0) - 1
            count[ch] = count[ch] - 1

            if count[ch] < 0:
                return False

        return True