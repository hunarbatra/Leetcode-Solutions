class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        strs = sorted(strs)
        if strs[0] == strs[-1]:
            return strs[0]

        for i in range(0, min(len(strs[0]), len(strs[-1]))):
            if strs[0][i] != strs[-1][i]:
                return strs[0][:i]
                
        if len(strs[0]) < len(strs[-1]):
            return strs[0]
        
        return ""