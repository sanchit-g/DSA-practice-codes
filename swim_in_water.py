from typing import List


def main():
    def swimInWater(grid: List[List[int]]) -> int:
        def find_path(height, i, j, visited):
            if not visited[i][j] and grid[i][j] <= height:
                visited[i][j] = 1
                if i-1 >= 0:
                    find_path(height, i-1, j, visited)
                if i+1 < n:
                    find_path(height, i+1, j, visited)
                if j-1 >= 0:
                    find_path(height, i, j-1, visited)
                if j+1 < n:
                    find_path(height, i, j+1, visited)

        def binary_search(l, r):
            while l < r:
                mid = (l + r) // 2
                visited = [[0]*n for _ in range(n)]
                find_path(mid, 0, 0, visited)
                if visited[n-1][n-1]:
                    r = mid
                else:
                    l = mid + 1
            return r

        n = len(grid)
        l, r = 0, max(max(x) for x in grid)
        return binary_search(l, r)

    grid = [[10, 12, 4, 6], [9, 11, 3, 5], [1, 7, 13, 8], [2, 0, 15, 14]]
    print(swimInWater(grid))


if __name__ == '__main__':
    main()
