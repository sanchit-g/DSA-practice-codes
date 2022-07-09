class Solution:
    def countVowelStrings(self, n: int) -> int:
        
        @lru_cache(maxsize=None)
        def count(i, n):
            
            # base case - if a string of length n in formed
            if n == 0:
                return 1
            
            # if i exceeds the number of vowels
            if i >= 5:
                return 0
            
            pick = count(i, n - 1)  # we picked the ith vowel, now form a string of length n - 1
            notPick = count(i + 1, n)   # we skipped the ith vowel, still we need to form a string of length n
            
            return pick + notPick
        
        return count(0, n)
