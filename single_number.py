from typing import List


def main():
    def singleNumber(nums: List[int]) -> int:
        # If we take XOR of zero and some bit, it will return that bit
        # a XOR 0 = a
        # If we take XOR of two same bits, it will return 0
        # a XOR a = 0
        # So we can XOR all bits together to find the unique number.
        a = 0
        for i in nums:
            a ^= i
        return a

    nums = [4, 1, 2, 1, 2]
    print(singleNumber(nums))


if __name__ == '__main__':
    main()
