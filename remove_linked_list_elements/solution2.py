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
        
        while head != None:
            if head.val == val:
                head = head.next
            else:
                break
        
        if head == None:
            return None
            
        p = head
        while p.next != None:
            q = p.next
            if q.val == val:
                p.next = q.next
            else:
                p = p.next
            
        return head
                
     