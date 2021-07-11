# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
# We have to find a pair of nodes A and B such that |A.val - B.val| is the highest and A is an 
# ancestor of B. For A to be an ancestor of B, A should reside in the path from root to leaf
# where B exists. So we just have to find A and B, which is actually the maximum and minimum value
# in the path. So we use DFS to traverse every path from root to leaf and on that path, we find the
# max and min valued node. Then check the difference between them and find the maximum difference.
class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        if not root:
            return 0
        stack = [(root, root.val, root.val)]
        res = 0
        while stack:
            node, high, low = stack.pop()
            res = max(res, abs(high-low)) 
            if node.left:
                stack.append((node.left, max(high, node.left.val), min(low, node.left.val)))
            if node.right:
                stack.append((node.right, max(high, node.right.val), min(low, node.right.val)))
        return res
