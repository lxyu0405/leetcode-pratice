class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """

        # nums2 is None
        if n == 0:
            return
        
        # nums1 is None
        if m == 0:
            for i in range(n):
                nums1[i] = nums2[i]
            return
            
        # None of them is None
        pos1 = m - 1
        pos2 = n - 1
        
        for i in range(m+n): # 0 ~ m+n-1
            cur_index = m + n - 1 -i
            if pos1 != -1 and (pos2 == -1 or nums1[pos1] >= nums2[pos2]):
                nums1[cur_index] = nums1[pos1]
                pos1 -= 1
            else:
                nums1[cur_index] = nums2[pos2]
                pos2 -= 1