# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        
        helper = ListNode(-1)
        helper.next = head
        
        p = helper
        
        while p.next != None:
            if p.next.val == val:
                p.next = p.next.next
            else:
                p = p.next
        
        return helper.next
     