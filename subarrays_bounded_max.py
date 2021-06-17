from typing import List


class Solution:
    def numSubarrayBoundedMax(self, nums: List[int], left: int, right: int) -> int:
        # Let count(bound) is the number of subarrays which have all elements less
        # than or equal to bound. Finally, count(right) - count(left-1) is our result.
        def count(bound):
            cnt = 0
            ans = 0
            for x in nums:
                cnt = cnt + 1 if x <= bound else 0
                ans += cnt
            return ans
        return count(right) - count(left-1)
