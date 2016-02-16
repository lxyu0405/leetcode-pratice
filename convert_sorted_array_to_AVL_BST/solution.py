# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        root = self.sortedArrayToBSTCore(nums, 0, len(nums)-1)
        return root

    
    def sortedArrayToBSTCore(self, nums, start, end):
        if start > end:
            return None

        # This code can be removed
        # if start == end:
        #     return TreeNode(nums[start])
            
        else:
            mid_index = (start + end)//2
            p = TreeNode(nums[mid_index])
            p.left = self.sortedArrayToBSTCore(nums, start, mid_index-1)
            p.right = self.sortedArrayToBSTCore(nums, mid_index+1, end)
            return p


