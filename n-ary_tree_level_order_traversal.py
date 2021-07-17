from typing import List
from collections import deque


class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        res = []
        queue = deque([root])
        while queue:
            curLevel = []
            for _ in range(len(queue)):
                node = queue.popleft()
                curLevel.append(node.val)
                for nbr in node.children:
                    queue.append(nbr)
            res.append(curLevel)
        return res
