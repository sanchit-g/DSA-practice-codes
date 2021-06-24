import os
import sys
from io import BytesIO, IOBase
from collections import defaultdict
from math import inf
import heapq

ONLINE_JUDGE = 1

# ___________________________________________________ #


def dijkstra(adj, n, source):
    visited, distance = [False] * n, [inf] * n
    distance[source] = 0
    heap = [(0, source)]
    heapq.heapify(heap)
    while heap:
        weight, node = heapq.heappop(heap)
        if visited[node] or weight > distance[node]:
            continue
        visited[node] = True
        for nbr, w in adj[node]:
            if distance[node] + w < distance[nbr]:
                distance[nbr] = distance[node] + w
                heapq.heappush(heap, (distance[nbr], nbr))
    return distance


def main():
    n, m = map(int, input().split())
    adj = defaultdict(list)
    for _ in range(m):
        a, b, c = [int(x) for x in input().split()]
        adj[a - 1].append((b - 1, c))
    print(*dijkstra(adj, n, 0))

# ___________________________________________________ #


BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)


def input():
    return sys.stdin.readline().rstrip("\r\n")


if __name__ == "__main__":
    if not ONLINE_JUDGE:
        sys.stdin = open('input.txt', 'r')
        sys.stdout = open('output.txt', 'w')
    main()
