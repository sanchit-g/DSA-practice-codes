from typing import List


class Solution:
    # using the pigeonhole principle
    def findDuplicate(self, nums: List[int]) -> int:
        low, high = 1, len(nums) - 1
        while low < high:
            mid = (high + low) // 2
            count = sum(i <= mid for i in nums)
            if count <= mid:
                low = mid + 1
            else:
                high = mid
        return high
