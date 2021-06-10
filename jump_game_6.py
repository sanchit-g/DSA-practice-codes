from typing import List
from collections import deque


class Solution:
    def maxResult(self, nums: List[int], k: int) -> int:
        n, deq = len(nums), deque([0])
        for i in range(1, n):
            nums[i] += nums[deq[0]]
            while deq and nums[deq[-1]] <= nums[i]:
                deq.pop()
            deq.append(i)
            if i - deq[0] >= k:
                deq.popleft()
        return nums[n - 1]
