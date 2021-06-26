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
    def findRedundantConnection(edges: List[List[int]]):
        n = len(edges)
        dsu = DSU(n)
        for u, v in edges:
            if dsu.find_set(u-1) == dsu.find_set(v-1):
                return [u, v]
            else:
                dsu.union_sets(u-1, v-1)

    edges = [[1, 2], [2, 3], [3, 4], [1, 4], [1, 5]]
    print(findRedundantConnection(edges))


if __name__ == '__main__':
    main()
