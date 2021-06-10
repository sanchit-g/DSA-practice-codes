import os
import sys
from io import BytesIO, IOBase

sys.setrecursionlimit(10**9)

ONLINE_JUDGE = 1

# ___________________________________________________ #


def dfs(matrix, row, col, n, m):
    matrix[row][col] = '#'
    rows = [-1, 0, 0, 1]
    cols = [0, -1, 1, 0]
    for k in range(4):
        i = row + rows[k]
        j = col + cols[k]
        if 0 <= i < n and 0 <= j < m and matrix[i][j] == '.':
            dfs(matrix, i, j, n, m)


def main():
    n, m = map(int, input().split())
    matrix = [list(input()) for _ in range(n)]
    count = 0
    for i in range(n):
        for j in range(m):
            if matrix[i][j] == '.':
                count += 1
                dfs(matrix, i, j, n, m)
    print(count)

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
