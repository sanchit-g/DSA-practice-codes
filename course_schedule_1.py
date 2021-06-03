from typing import List
from collections import defaultdict


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        pre = defaultdict(list)
        for a, b in prerequisites:
            pre[a].append(b)
        seen = [0] * numCourses

        def dfs(a):
            if seen[a]:
                return seen[a] == 1
            seen[a] = -1
            if any(not dfs(b) for b in pre[a]):
                return False
            seen[a] = 1
            return True

        return True if all(dfs(x) for x in range(numCourses)) else False
