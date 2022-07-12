# similar to House Robber

class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        N = max(nums) + 1
        freq = [0] * N
        
        for n in nums:
            freq[n] += n
            
        def rob(nums):
            n = len(nums)
            
            if n == 0:
                return 0
            
            if n == 1:
                return nums[0]
            
            if n == 2:
                return max(nums)
            
            dp = [0] * (n + 1)
            dp[1], dp[2] = nums[0], max(nums[0], nums[1])
            
            for i in range(3, n + 1):
                dp[i] = max(dp[i-2] + nums[i-1], dp[i-1])
            
            return dp[n]
        
        return rob(freq)
