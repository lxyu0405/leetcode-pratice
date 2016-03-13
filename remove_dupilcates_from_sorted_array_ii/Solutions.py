class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0

        if len(nums) <= 2:
            return len(nums)

        ai = 0

        pre_num = nums[0]
        counter = 1
        for aj in xrange(1,len(nums)):
            if nums[aj] != pre_num:
                nums[ai+1], nums[aj] = nums[aj], nums[ai+1]
                pre_num = nums[ai+1]
                counter = 1
                ai += 1
            else: # nums[aj] == nums[aj-1]
                if counter < 2: # counter must be 1
                    nums[ai+1], nums[aj] = nums[aj], nums[ai+1]
                    counter += 1
                    ai += 1
                else: # counter == 2
                    pass

        return ai+1







if __name__ == "__main__":
    nums = [1,1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,3,4,4,4,4,4,8,8,8,8,8,8,8,9,9,9,9,9]
    test = Solution()
    print(test.removeDuplicates(nums))
    print(nums)



