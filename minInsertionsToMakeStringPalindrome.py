class Solution:
    def minInsertions(self, s: str) -> int:
        
        @lru_cache(maxsize=None)
        def dp(i, j):
            
            if i >= j:
                return 0
            
            if s[i] == s[j]:
                return dp(i + 1, j - 1)
            
            # if s[i] != s[j], then we can either add a char at ith index or at jth index
            else:
                return 1 + min(dp(i + 1, j), dp(i, j - 1))
        
        return dp(0, len(s) - 1)
