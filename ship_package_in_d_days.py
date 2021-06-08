from typing import List


class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        def check(capacity):
            total, day = 0, 1
            for wt in weights:
                total += wt
                if total > capacity:
                    day += 1
                    total = wt
            if day > days:
                return False
            return True
        low, high, ans = max(weights), sum(weights), 0
        while low <= high:
            mid = low + (high - low) // 2
            if check(mid):
                ans = mid
                high = mid - 1
            else:
                low = mid + 1
        return ans
