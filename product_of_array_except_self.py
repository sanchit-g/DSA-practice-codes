from typing import List


def main():
    # product of array except nums[i] = product of numbers to the left of nums[i] * product of numbers to the right of nums[i]
    def productExceptSelf(nums: List[int]) -> List[int]:
        n = len(nums)
        leftProduct = [1] * n
        rightProduct = [1] * n

        leftProduct[0] = 1
        rightProduct[n - 1] = 1

        for i in range(1, n):
            leftProduct[i] = leftProduct[i - 1] * nums[i - 1]

        for i in range(n - 2, - 1, - 1):
            rightProduct[i] = rightProduct[i + 1] * nums[i + 1]

        res = [1] * n
        for i in range(n):
            res[i] = leftProduct[i] * rightProduct[i]

        return res

    nums = [1, 2, 3, 4]
    print(productExceptSelf(nums))


if __name__ == '__main__':
    main()
