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
        tail = head = None

        while l1 is not None or l2 is not None or carry == 1:
        	temp = 0
        	if l1 is not None:
        		temp += l1.val
        		l1 = l1.next
        	if l2 is not None:
        		temp += l2.val
        		l2 = l2.next

        	temp += carry

        	val = temp % 10
        	carry = temp / 10

        	if head is None:
        		head = ListNode(val)
        		tail = head
        	else:
        		head.next = ListNode(val)
        		head = head.next

        return tail