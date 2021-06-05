from typing import List
from collections import deque


class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        deadends = set(deadends)
        seen = set()
        seen.add('0000')
        q = deque(['0000'])
        min_steps = 0
        while q:
            size = len(q)
            for i in range(size):
                lockPos = q.popleft()
                if lockPos in deadends:
                    continue
                if lockPos == target:
                    return min_steps
                for i in range(4):
                    curPos = int(lockPos[i])
                    s1 = lockPos[0:i] + ('0' if curPos == 9 else str((curPos + 1))) + lockPos[i+1:]
                    s2 = lockPos[0:i] + ('9' if curPos == 0 else str((curPos - 1))) + lockPos[i+1:]
                    if s1 not in seen and s1 not in deadends:
                        seen.add(s1)
                        q.append(s1)
                    if s2 not in seen and s2 not in deadends:
                        seen.add(s2)
                        q.append(s2)
            min_steps += 1
        return -1
