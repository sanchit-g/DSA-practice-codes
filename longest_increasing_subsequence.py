from typing import List
from bisect import bisect_left


def main():
    # Naive DP approach
    def lengthOfLIS(nums: List[int]) -> int:
        n = len(nums)
        dp = [1] * n
        for i in range(1, n):
            for j in range(i):
                if nums[j] < nums[i] and dp[i] <= dp[j]:
                    dp[i] = 1 + dp[j]
        return max(dp)

    # Binary Search + DP approach
    def lengthOfLIS2(nums: List[int]) -> int:
        sub = []
        for num in nums:
            i = bisect_left(sub, num)
            # If num is greater than any element in sub
            if i == len(sub):
                sub.append(num)
            # Otherwise, replace the first element in sub greater than or equal to num
            else:
                sub[i] = num
        return len(sub)

    nums = [10, 9, 2, 5, 3, 7, 101, 18]
    print(lengthOfLIS2(nums))


if __name__ == '__main__':
    main()
