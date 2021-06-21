from typing import List


def main():
    def checkPossibility(nums: List[int]) -> bool:
        cnt = 0
        for i in range(len(nums)-1):
            if nums[i] > nums[i+1]:
                cnt += 1
                if (cnt > 1) or ((i-1 >= 0 and nums[i-1] > nums[i+1]) and (i+2 < len(nums) and nums[i+2] < nums[i])):
                    return False
        return True

    nums = [3, 4, 2, 3]
    print(checkPossibility(nums))


if __name__ == '__main__':
    main()
