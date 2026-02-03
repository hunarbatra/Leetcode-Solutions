from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # h = {}
        h = defaultdict(list) # init dict of lists

        for s in strs:
            key = "".join(sorted(s))
            h[key].append(s)
            # if key not in h:
            #     h[key] = [s]
            # else:
            #     h[key].append(s)
            
        return list(h.values())

  