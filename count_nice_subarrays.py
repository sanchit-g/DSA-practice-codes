from typing import List


class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        
        def atMostK(k):
            i, count = 0, 0
            for j in range(len(nums)):
                if nums[j] & 1:
                    k -= 1
                while k < 0:
                    if nums[i] & 1:
                        k += 1
                    i += 1
                count += j - i + 1
            return count
        
        return atMostK(k) - atMostK(k-1)
