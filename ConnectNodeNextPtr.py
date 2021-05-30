class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next


class Solution:
    def connect(self, root: 'Node') -> 'Node':
        self.connect_utility(root)
        return root

    def connect_utility(self, node: 'Node') -> None:
        if not node:
            return
        # nxt stores pointer to the first node of next level
        curr, nxt = node, node.left
        while nxt:
            curr.left.next = curr.right
            if curr.next:
                curr.right.next = curr.next.left
                curr = curr.next
            else:
                curr = nxt
                nxt = curr.left
