class Solution:
    def minSideJumps(self, obstacles: List[int]) -> int:
        n = len(obstacles) - 1
        dp = [[0] * 3 for _ in range(n)]
        
        # base case
        dp[0][0] = dp[0][2] = 1
        
        for i in range(1, n):
            for j in range(0, 3):
                if obstacles[i] == j+1 or obstacles[i-1] == j+1:
                    dp[i][j] = math.inf
                else:
                    dp[i][j] = min(dp[i-1][j], dp[i-1][(j+1)%3] + 1, dp[i-1][(j+2)%3] + 1)
        return min(dp[-1])
