from functools import lru_cache

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        @lru_cache(maxsize=None)
        def solve(idx, buy):
            # base case
            if idx == len(prices):
                return 0
            
            if buy == 1:
                profit = max((-prices[idx] + solve(idx+1, 0)), solve(idx+1, 1))
            else:
                profit = max((prices[idx] + solve(idx+1, 1)), solve(idx+1, 0))
            
            return profit
        
        return solve(0, 1)
