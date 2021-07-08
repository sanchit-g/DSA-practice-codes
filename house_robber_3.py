class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def helper(self, root: TreeNode):
        if not root:
            return 0
        if root in self.cache:
            return self.cache[root]
        val = 0
        if root.left:
            val += self.helper(root.left.left) + self.helper(root.left.right)
        if root.right:
            val += self.helper(root.right.left) + self.helper(root.right.right)
        res = max(root.val + val, self.helper(root.left) + self.helper(root.right))
        self.cache[root] = res
        return self.cache[root]
    
    def rob(self, root: TreeNode) -> int:
        self.cache = {}
        return self.helper(root)
