from typing import List
from collections import deque


def main():
    def isBipartite(graph: List[List[int]]) -> bool:

        def bfs(i):
            visited[i] = True
            queue = deque([i])
            while queue:
                curr = queue.popleft()
                for nbr in graph[curr]:
                    if not visited[nbr]:
                        visited[nbr] = True
                        colors[nbr] = not colors[curr]
                        queue.append(nbr)
                    else:
                        if colors[nbr] == colors[curr]:
                            return False
            return True

        n = len(graph)
        visited = [False] * n
        colors = [-1] * n

        for i in range(n):
            if not visited[i]:
                visited[i] = True
                colors[i] = 0
                if not bfs(i):
                    return False
        return True

    graph = [[1, 2, 3], [0, 3, 4], [0, 3], [0, 1, 2], [1]]
    print(isBipartite(graph))


if __name__ == '__main__':
    main()
