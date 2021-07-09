# https://leetcode.com/problems/contiguous-array/discuss/653061/Python-Detailed-explanation-O(n)-timeandspace-cumulative-sums
class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            if nums[i] == 0:
                nums[i] = -1
        prefixArray = [0] * n
        total = 0
        for i, num in enumerate(nums):
            total += num
            prefixArray[i] = total
        indices = collections.defaultdict(list)
        indices[0] = [-1, -1]
        for i, prefixSum in enumerate(prefixArray):
            if prefixSum not in indices:
                indices[prefixSum] = [i, i]
            else:
                indices[prefixSum][1] = i
        # print(indices)
        ans = 0
        for prefixSum in indices:
            ans = max(ans, indices[prefixSum][1] - indices[prefixSum][0])
        return ans
