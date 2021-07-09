class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        level, ans, max_sum = 0, 0, float('-inf')
        queue = deque([root])
        while queue:
            curr_sum = 0
            level += 1
            for _ in range(len(queue)):
                node = queue.popleft()
                curr_sum += node.val
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            if curr_sum > max_sum:
                max_sum = curr_sum
                ans = level
        return ans
