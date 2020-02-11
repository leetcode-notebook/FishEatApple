# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head==None:
            return None
        if head.next==None:
            return head
        node=self.deleteDuplicates(head.next)
        if head.val==node.val:
            return node
        else:
            head.next=node
            return head