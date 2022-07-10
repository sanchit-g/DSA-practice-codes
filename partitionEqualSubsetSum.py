class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        
        N, total = len(nums), sum(nums)
        
        if total % 2 != 0:
            return False
        
        target = total // 2
        
        @lru_cache(None)
        def dfs(i, curr_sum):
            
            # base case
            if i == N:
                if curr_sum == target:
                    return True
                return False
            
            # pick 
            if dfs(i+1, curr_sum + nums[i]):
                return True
            
            # not pick
            return dfs(i+1, curr_sum)
        
        return dfs(0, 0)
