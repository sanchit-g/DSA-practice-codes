class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# https://bit.ly/3hzHEDH


class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        left_head, right_head = ListNode(), ListNode()  # dummy nodes
        left_tail, right_tail = left_head, right_head
        while head:
            if head.val < x:
                left_tail.next = head
                left_tail = left_tail.next
            else:
                right_tail.next = head
                right_tail = right_tail.next
            head = head.next
        left_tail.next = right_head.next
        right_tail.next = None
        return left_head.next
