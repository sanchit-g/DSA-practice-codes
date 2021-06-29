from typing import List


def main():
    def minSubArrayLen(target: int, nums: List[int]) -> int:
        i, total, res = 0, 0, len(nums) + 1
        for j in range(len(nums)):
            total += nums[j]
            while total >= target:
                res = min(res, j - i + 1)
                total -= nums[i]
                i += 1
        return res if res <= len(nums) else 0

    nums = [2, 3, 1, 2, 4, 3]
    target = 7
    print(minSubArrayLen(target, nums))


if __name__ == '__main__':
    main()
