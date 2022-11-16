class Solution:
    def equalFrequency(self, word: str) -> bool:
        def checkFreq(word: str) -> bool:
            count = Counter(word)
            check_count = set()
            for k, v in count.items():
                check_count.add(v)
            return True if len(check_count) == 1 else False
    
        for i in range(len(word)):
            if checkFreq(word[:i] + word[i+1:]):
                return True
        return False
            
            
            