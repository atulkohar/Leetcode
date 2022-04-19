# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        counter = {}

        for list in lists:
            while list:
                if list.val not in counter:
                    counter[list.val] = 0
                counter[list.val] += 1
                list = list.next

        dummy = ListNode()
        cur = dummy

        for key, count in sorted(counter.items()):
            while count:
                new_node = ListNode(key)
                cur.next = new_node
                cur = new_node
                count -= 1

        return dummy.next