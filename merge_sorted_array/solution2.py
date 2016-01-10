class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """

        pos1 = m - 1
        pos2 = n - 1
        cur_index = m + n - 1
        
        while pos1 >= 0 and pos2 >= 0:
            if nums1[pos1] >= nums2[pos2]:
                nums1[cur_index] = nums1[pos1]
                pos1 -= 1
            else:
                nums1[cur_index] = nums2[pos2]
                pos2 -= 1
            cur_index -= 1
        
        while pos2 >= 0:
            nums1[cur_index] = nums2[pos2]
            pos2 -= 1
            cur_index -= 1
          