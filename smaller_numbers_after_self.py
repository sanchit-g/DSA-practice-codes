# For reference : https://www.youtube.com/watch?v=NOykDuH1_OY
from typing import List


class FenwickTree:
    def __init__(self, n: int):
        self.BIT = [0] * (n + 1)

    def sum(self, x: int) -> int:
        ans = 0
        while x:
            ans += self.BIT[x]
            x -= x & -x
        return ans

    def update(self, x: int, val: int):
        while x < len(self.BIT):
            self.BIT[x] += val
            x += x & -x


class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        m = {n: i + 1 for i, n in enumerate(sorted(set(nums)))}
        nums = [m[n] for n in nums]
        ft = FenwickTree(len(nums))
        res = []
        for i in reversed(nums):
            res.append(ft.sum(i - 1))
            ft.update(i, 1)
        return res[::-1]
