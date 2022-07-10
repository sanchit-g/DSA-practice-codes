class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        
        N = len(nums)
        
        @lru_cache(maxsize=None)
        def solve(curr_sum, index):
            
            # base case
            if index == N and curr_sum == target:
                return 1
            
            if index == N:
                return 0
            
            # assign positive sign to nums[index]
            pos = solve(curr_sum + nums[index], index + 1)
            
            # assign negative sign to nums[index]
            neg = solve(curr_sum - nums[index], index + 1)
            
            # count total no of ways
            return pos + neg
        
        return solve(0, 0)
