class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        
        @lru_cache(maxsize=None)
        def solve(l, r):
            
            ans = float('inf')
            
            for cut in cuts:
                # we need to consider cuts that lies b/w l and r
                if cut >= r or cut <= l:
                    continue
                
                minLeft = solve(l, cut)
                minRight = solve(cut, r)
                
                ans = min(ans, minLeft + minRight + r - l)
            
            # this means there was no cut between l and r
            # then ans should be 0
            if ans == float('inf'):
                ans = 0
                
            return ans
        
        return solve(0, n)
