from typing import List
from collections import defaultdict


def main():
    def subarraySum(nums: List[int], k: int) -> int:
        curr_sum, count = 0, 0
        mapping = defaultdict(int)
        mapping[0] = 1
        for x in nums:
            curr_sum += x
            # subarray sum for [i, j] = prefix[j] - prefix[i - 1]
            # k = sum[0...j] - sum[0...i-1]
            # which implies, prefix[i-1] = sum[0...j] - k
            # we need to count no. of values = sum[0...j] - k in prefix array
            # we store all previous values of prefix array in hashmap so
            # that we can find them in O(1), making overall complexity = O(n)
            need = curr_sum - k
            count += mapping[need]
            mapping[curr_sum] += 1
        return count

    nums = [3, 4, 7, 2, -3, 1, 4, 2, 1]
    k = 7
    print(subarraySum(nums, k))


if __name__ == '__main__':
    main()
