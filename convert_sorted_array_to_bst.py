from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def recurse(self, start, end, nums):
        while start <= end:
            mid = start + (end - start) // 2
            root = TreeNode(nums[mid])
            root.left = self.recurse(start, mid-1, nums)
            root.right = self.recurse(mid+1, end, nums)
            return root

    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        return self.recurse(0, len(nums) - 1, nums)
