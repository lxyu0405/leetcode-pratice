# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):

    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0
        tail, head = None
        while l1 is not None and l2 is not None:
        	temp = l1.val + l2.val + carry
        	val = temp % 10
        	carry = temp / 10
        	if head is None:
        		head = ListNode(val)
        		tail = head
        	else:
        		head.next = ListNode(val)
        		head = head.next
        	l1 = l1.next
        	l2 = l2.next

        rem = None
        if l1 is None:
        	rem = l2
        else:
        	rem = l1

        while rem is not None :
        	temp = rem.val + carry
        	val = temp % 10
        	carry = temp / 10
        	if head is None:
        		head = ListNode(val)
        		tail = head
        	else:
        		head.next = ListNode(val)
        		head = head.next
        	rem = rem.next

        if carry == 1:
        	head.next = ListNode(1)
        	head = head.next

        return tail
           