# almost similar to House Robber 2 (only with added constraint that we can pick at max n/3 elements

class Solution:
    def maxSizeSlices(self, slices: List[int]) -> int:
        n = len(slices)
        cache = {}
        
        def solve(ind, n):
            # base case
            if n == 0 or ind >= len(slices):
                return 0
            
            if (ind, n) in cache:
                return cache[(ind, n)]
            
            pick = slices[ind] + solve(ind + 2, n - 1)
            notPick = 0 + solve(ind + 1, n)
            
            cache[(ind, n)] = max(pick, notPick)
            return cache[(ind, n)]
        
        ans1 = solve(1, n//3)
        
        cache.clear()
        
        #remove the last element
        slices.pop()
        ans2 = solve(0, n//3)
        
        return max(ans1, ans2)
