# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        
        p = head
        cnt = 0
        while p is not None:
            p = p.next
            cnt += 1
            
        pre_cnt = cnt - n + 1
        
        if pre_cnt <= 0:
            return head
        if pre_cnt == 1:
            return head.next
        
        p = head
        for i in range(pre_cnt-2):
            p = p.next
        
        p.next = p.next.next
      
        return head