class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    max_value = float('-inf')

    def maxPathSum(self, root: TreeNode) -> int:
        self.recur(root)
        return self.max_value

    def recur(self, node: TreeNode):
        if node is None:
            return 0
        left_subtree = max(0, self.recur(node.left))
        right_subtree = max(0, self.recur(node.right))

        self.max_value = max(self.max_value, left_subtree + right_subtree + node.val)
        return node.val + max(left_subtree, right_subtree)
