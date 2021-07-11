from typing import List


def main():
    def singleNonDuplicate(nums: List[int]) -> int:
        # Reference : https://bit.ly/3e6CLkO
        lo, hi = 0, len(nums) - 1
        while lo < hi:
            mid = (lo + hi) // 2
            # odd xor 1 = odd - 1
            # even xor 1 = even + 1
            if nums[mid] == nums[mid ^ 1]:
                lo = mid + 1
            else:
                hi = mid
        return nums[hi]

    nums = [1, 1, 2, 3, 3, 4, 4, 8, 8]
    print(singleNonDuplicate(nums))


if __name__ == '__main__':
    main()
