class Solution:
    def minCost(self, houses: List[int], cost: List[List[int]], m: int, n: int, target: int) -> int:
        
        @lru_cache(maxsize=None)
        def helper(i, t, p):
            
            if i == len(houses):
                return 0 if t == 0 else float('inf')
            
            if houses[i] == 0:
                ans = min(helper(i + 1, t - (nc != p), nc) + cost[i][nc - 1] for nc in range(1, n + 1))
            else:
                ans = helper(i + 1, t - (houses[i] != p), houses[i])
                
            return ans
            
        res = helper(0, target, -1)
        return res if res < float('inf') else -1
