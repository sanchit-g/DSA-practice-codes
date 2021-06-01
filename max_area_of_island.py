from typing import List


class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid[0]), len(grid)
        DIR = [0, 1, 0, -1, 0]

        def dfs(row, col):
            if row < 0 or row == n or col < 0 or col == m or grid[row][col] == 0:
                return 0
            grid[row][col] = 0
            ans = 1
            for i in range(4):
                ans += dfs(row + DIR[i], col + DIR[i+1])
            return ans

        res = 0
        for row in range(n):
            for col in range(m):
                res = max(res, dfs(row, col))
        return res
