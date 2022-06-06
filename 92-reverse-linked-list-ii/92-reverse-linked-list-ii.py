# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        prev,curr = None,head
        while left>1:
            prev = curr
            curr = curr.next
            right-=1
            left-=1
        node1,node2 = prev,curr
        while right>0:
            nextN = curr.next
            curr.next = prev
            prev = curr
            curr = nextN
            right-=1
        node2.next = curr
        if node1:
            node1.next = prev
            return head
        return prev