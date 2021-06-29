from typing import List


def main():
    def longestOnes(nums: List[int], k: int) -> int:
        i = 0
        for j in range(len(nums)):
            if nums[j] == 0:
                k -= 1
            # if k < 0 then we need to move the left
            # part of the window forward to try and
            # remove the extra 0's
            if k < 0:
                if nums[i] == 0:
                    k += 1
                i += 1
        return j - i + 1

    nums = [0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1]
    k = 3
    print(longestOnes(nums, k))


if __name__ == '__main__':
    main()
