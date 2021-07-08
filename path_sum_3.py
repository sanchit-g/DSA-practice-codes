from collections import defaultdict


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def dfs(self, root, target, currPathSum):
        # exit condition
        if not root:
            return

        currPathSum += root.val

        # update result and cache
        self.result += self.cache[currPathSum - target]
        self.cache[currPathSum] += 1

        # DFS breakdown
        self.dfs(root.left, target, currPathSum)
        self.dfs(root.right, target, currPathSum)

        # when move to a different branch, the currPathSum is no longer available
        self.cache[currPathSum] -= 1

    def pathSum(self, root: TreeNode, target: int) -> int:
        # define global result and cache var
        self.result = 0
        self.cache = defaultdict(int)
        self.cache[0] = 1

        self.dfs(root, target, 0)

        return self.result
