# this is an example of Matrix Chain Multiplication

class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        
        n = len(nums)
        
        # add two dummy balloon with value 1 in the beginning and end
        nums.append(1)
        nums.insert(0, 1)
        
        memo = {}
        
        def solve(i, j):
            
            # base case
            if i > j:
                return 0
            
            if (i, j) in memo:
                return memo[(i, j)]
            
            ans = 0
            
            for k in range(i, j + 1):
                # kth balloon is the last one to burst
                # this means, all the balloons from (i, k-1) and (k+1, j) are already burst
                # this makes balloon i, balloon k and balloon j adjacent
                ans = max(ans, solve(i, k - 1) + solve(k + 1, j) + (nums[k] * nums[i - 1] * nums[j + 1]))
            
            memo[(i, j)] = ans
            return ans
        
        # we call the solve function from 2nd balloon to 2nd last balloon
        # this is because 1st and the last balloons are dummy
        return solve(1, n)
