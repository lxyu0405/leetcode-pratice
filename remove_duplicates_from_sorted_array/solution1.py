class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 2:
            return len(nums)
        
        list_len = len(nums)
        pos = 0
        
        counter = 0
        
        while counter < list_len-1:
            if nums[pos] == nums[pos+1]:
                nums.remove(nums[pos])
            else:
                pos += 1
            counter += 1
                
        return len(nums)