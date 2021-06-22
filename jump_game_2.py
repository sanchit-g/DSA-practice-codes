from typing import List
from functools import lru_cache


def main():
    # Brute force approach
    # def jump(nums: List[int]) -> int:
    #     def recurse(pos):
    #         if pos >= len(nums) - 1:
    #             return 0
    #         min_jumps = 1001
    #         for i in range(1, nums[pos]+1):
    #             min_jumps = min(min_jumps, 1 + recurse(pos+i))
    #         return min_jumps
    #     return recurse(0)

    # Recursive DP with Memoization
    def jump(nums: List[int]) -> int:
        n = len(nums)

        @lru_cache(None)
        def solve(pos):
            if pos == n-1:
                return 0
            ans = 5753
            max_jump = min(n-1, pos + nums[pos])
            for i in range(pos+1, max_jump+1):
                ans = min(ans, solve(i) + 1)
            return ans

        return solve(0)

    nums = [5, 6, 4, 4, 6, 9, 4, 4, 7, 4, 4, 8, 2, 6, 8, 1, 5, 9, 6,
            5, 2, 7, 9, 7, 9, 6, 9, 4, 1, 6, 8, 8, 4, 4, 2, 0, 3, 8, 5]
    print(jump(nums))


if __name__ == '__main__':
    main()
