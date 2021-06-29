class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# We keep three pointers as with any other reverse linked list problems: pre, curr, next.
# We can split all algorithm into 3 steps:

# 1. Do left-1 steps to reach the first point of range we need to reverse.
# 2. Reverse range [left - right], using 3 pointers approach.
# 3. Finally we need to fix connections for the start and for the end of reversed list, using
#    saved pointer to pre.


class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        dummy = ListNode(None)
        dummy.next = head
        prev = dummy
        for i in range(left - 1):
            prev = prev.next
        curr = prev.next
        nxt = curr.next
        for i in range(right - left):
            temp = nxt.next
            nxt.next = curr
            curr = nxt
            nxt = temp
        prev.next.next = nxt
        prev.next = curr
        return dummy.next
