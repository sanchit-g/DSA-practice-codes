class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# https://bit.ly/3duPpK3


class Solution:
    def flatten(self, root: TreeNode) -> None:
        curr = root
        while curr:
            if curr.left:
                p = curr.left
                while p.right:
                    p = p.right
                p.right = curr.right
                curr.right = curr.left
                curr.left = None
            curr = curr.right
