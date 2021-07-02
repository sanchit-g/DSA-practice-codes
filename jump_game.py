class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        if n == 1:
            return True
        index_to_reach = n - 1
        for i in range(n-2, -1, -1):
            if i + nums[i] >= index_to_reach:
                index_to_reach = i
        return index_to_reach == 0
