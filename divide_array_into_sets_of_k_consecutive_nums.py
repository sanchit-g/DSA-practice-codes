from typing import List
from collections import Counter


def main():
    def isPossibleDivide(nums: List[int], k: int) -> bool:
        hashmap = Counter(nums)
        for num in sorted(hashmap):
            while hashmap[num]:
                for i in range(num, num+k):
                    if not hashmap[i]:
                        return False
                    hashmap[i] -= 1
        return True

    nums = [3, 2, 1, 2, 3, 4, 3, 4, 5, 9, 10, 11]
    k = 3
    print(isPossibleDivide(nums, k))


if __name__ == '__main__':
    main()
