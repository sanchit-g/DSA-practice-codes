class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        # fast will finally point at the last node
        # slow will finally point to the previous node of the target node
        fast, slow = head, head
        # let the fast pointer move n steps ahead of the slow pointer
        for _ in range(n):
            fast = fast.next
        # when we need to delete the first node of List [n = len(List)]
        if not fast:
            return slow.next
        while fast.next:
            fast, slow = fast.next, slow.next
        slow.next = slow.next.next
        return head
