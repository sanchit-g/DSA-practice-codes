from typing import List
from heapq import heappush, heappop


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        head = curr = ListNode(0)
        min_heap = []
        for x in lists:
            while x:
                heappush(min_heap, x.val)
                x = x.next
        while min_heap:
            curr.next = ListNode(heappop(min_heap))
            curr = curr.next
        return head.next
