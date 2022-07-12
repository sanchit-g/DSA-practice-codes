# for reference : https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/discuss/731233/a-few-solutions

class Solution:
    def minDifference(self, nums: List[int]) -> int:
        n = len(nums)
        
        if n <= 4:
            return 0
        
        nums.sort()
        
        i, j = 0, n - 4
        ans = float('inf')
        
        while j < n:
            ans = min(ans, nums[j] - nums[i])
            j += 1
            i += 1
        
        return ans
