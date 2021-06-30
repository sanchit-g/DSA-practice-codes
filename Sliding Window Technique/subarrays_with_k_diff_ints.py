from typing import List
from collections import defaultdict


def main():
    def atMostK(nums, k):
        lookup = defaultdict(int)
        i, ans = 0, 0
        for j in range(len(nums)):
            if lookup[nums[j]] == 0:
                k -= 1
            lookup[nums[j]] += 1
            while k < 0:
                lookup[nums[i]] -= 1
                if lookup[nums[i]] == 0:
                    k += 1
                i += 1
            # The new element a[j] will contribute (j - i + 1) new sub arrays.
            # if we add c to [a,b], the new element c will contribute 3 new subarrays
            # and the total number of sub arrays become 3 + 3 = 6.
            # if we add d to [a,b,c], the new element d will contribute 4 new subarrays
            # and the total number of sub arrays become 6 + 4 = 10.
            ans += j - i + 1
        return ans

    def subarraysWithKDistinct(nums: List[int], k: int) -> int:
        # subArrayExactlyK = subArrayAtMostK - subArrayAtMostK - 1
        return atMostK(nums, k) - atMostK(nums, k - 1)

    nums = [1, 2, 1, 2, 3]
    k = 2
    print(subarraysWithKDistinct(nums, k))


if __name__ == '__main__':
    main()
