from typing import List
from collections import defaultdict


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        pre = defaultdict(list)
        for a, b in prerequisites:
            pre[a].append(b)
        self.res, seen = [], [0] * numCourses

        def dfs(a):
            if seen[a]:
                return seen[a] == 1
            seen[a] = -1
            if any(not dfs(b) for b in pre[a]):
                return False
            seen[a] = 1
            self.res.append(a)
            return True

        return self.res if all(dfs(x) for x in range(numCourses)) else []
