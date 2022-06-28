from functools import lru_cache

class Solution:
    def numRollsToTarget(self, A: int, B: int, C: int) -> int:
        if C < A:
            return 0
        
        @lru_cache(maxsize=None)
        def solve(A, B, C):
            if A == 0 and C == 0:
                return 1
            if C < A or C > (A*B) or A == 0 or C == 0:
                return 0
            count = 0
            for i in range(1, B+1):
                if (C - i) >= 0:
                    count += solve(A - 1, B, C- i)
                    count %= 1000000007
            return count
        
        return solve(A, B, C)
