# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        n1 = self.reverse_and_get_int(l1)
        n2 = self.reverse_and_get_int(l2)
        n3 = n1 + n2

        res = [int(x) for x in str(n3)][::-1]
        
        dummy = ListNode()
        output = dummy
        
        for n in res:
            dummy.next = ListNode(n)
            dummy = dummy.next
        
        return output.next
        
    def reverse_and_get_int(self, head) -> int:
        prev, curr = None, head
        
        while curr:
            curr_n = curr.next
            curr.next = prev
            prev = curr
            curr = curr_n
            
        num = prev.val
        prev = prev.next
        
        while prev:
            num = num * 10
            num += prev.val
            prev = prev.next
        
        return num