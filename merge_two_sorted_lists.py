# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        p1, p2 = l1, l2
        head = pr = None
        while p1 is not None or p2 is not None:
            t_val = 0
            if p1 is None:
                t_val = p2.val
                p2 = p2.next
            elif p2 is None:
                t_val = p1.val
                p1 = p1.next
            else:
                if p1.val < p2.val:
                    t_val = p1.val
                    p1 = p1.next
                else:
                    t_val = p2.val
                    p2 = p2.next

            new_node = ListNode(t_val)
            if pr is None:
                head = pr = new_node
            else:
                pr.next = new_node
                pr = pr.next
        
        return head