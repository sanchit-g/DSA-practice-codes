from collections import deque


class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        n, m = len(image), len(image[0])
        oldColor = image[sr][sc]
        if oldColor != newColor:
            queue = deque([(sr, sc)])
            while queue:
                i, j = queue.popleft()
                image[i][j] = newColor
                for x, y in ((i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)):
                    if 0 <= x < n and 0 <= y < m and image[x][y] == oldColor:
                        queue.append((x, y))
        return image
