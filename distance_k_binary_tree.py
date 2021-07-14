# for reference : https://bit.ly/3r9ZNfJ
from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def buildParentMap(self, node, parent, parent_map):
        if not node:
            return
        parent_map[node] = parent
        self.buildParentMap(node.left, node, parent_map)
        self.buildParentMap(node.right, node, parent_map)

    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        parent_map = {}
        self.buildParentMap(root, None, parent_map)

        visited = set()
        res = []

        def dfs(node, dist):
            if not node:
                return
            if node in visited:
                return
            visited.add(node)
            if dist == k:
                res.append(node.val)
            elif dist < k:
                dfs(node.left, dist+1)
                dfs(node.right, dist+1)
                dfs(parent_map[node], dist+1)

        dfs(target, 0)
        return res
