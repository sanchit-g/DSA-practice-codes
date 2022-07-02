class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        
        @lru_cache(maxsize=None)
        def solve(idx, buy, cap):
            # base case
            if idx == len(prices) or cap == 0:
                return 0
            
            if buy == 1:
                profit = max((-prices[idx] + solve(idx+1, 0, cap)), solve(idx+1, 1, cap))
            else:
                profit = max((prices[idx] + solve(idx+1, 1, cap-1)), solve(idx+1, 0, cap))
            
            return profit
        
        return solve(0, 1, k)
