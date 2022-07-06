# dp(i, dr) is the longest turbulent subarray, which ends with position i and such that its last step was incresing if dr = 1 and decreasing if dr = -1
class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        
        @lru_cache(maxsize=None)
        def dp(i, dr):
            # if the current dir is +ve and arr(i) - arr(i-1) is also +ve
            # then terminate the subarray here. we cannot continue further.
            if i == 0 or (arr[i] - arr[i-1]) * dr >= 0:
                return 1
            
            return dp(i-1, -dr) + 1
        
        ans = 0
        
        # check for all possibilities and look for the highest score
        for dr in [-1, 1]:
            for i in range(len(arr)):
                ans = max(ans, dp(i, dr))
                
        return ans
