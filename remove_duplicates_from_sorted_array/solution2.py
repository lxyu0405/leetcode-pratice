class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        Note: It doesn't matter what you leave beyond the new length. !!
        """
        if nums is None:
            return 0
        
        if len(nums) < 2:
            return len(nums)

        counter = 1

        for num in nums[1:]:
            if num != nums[counter-1]:
                nums[counter] = num
                counter += 1
                
        return counter