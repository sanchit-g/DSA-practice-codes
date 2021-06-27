from typing import List


class DSU:
    def __init__(self, N):
        self.parent = list(range(N))

    def find_set(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find_set(self.parent[x])
        return self.parent[x]

    def union_sets(self, a, b):
        a = self.find_set(a)
        b = self.find_set(b)
        if a != b:
            self.parent[b] = a


def main():
    def makeConnected(n: int, connections: List[List[int]]) -> int:
        if len(connections) < n - 1:
            return -1
        dsu = DSU(n)
        for a, b in connections:
            dsu.union_sets(a, b)
        s = set()
        for i in range(n):
            s.add(dsu.find_set(i))
        # here, len(s) is number of connected components
        return len(s) - 1

    n, connections = 11, [[1, 4], [0, 3], [1, 3], [3, 7], [2, 7], [
        0, 1], [2, 4], [3, 6], [5, 6], [6, 7], [4, 7], [0, 7], [5, 7]]
    print(makeConnected(n, connections))


if __name__ == '__main__':
    main()
