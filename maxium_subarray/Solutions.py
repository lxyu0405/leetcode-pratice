class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0

        max_nums = [x for x in nums]
        for i in xrange(1,len(nums)):
            max_nums[i] = max(nums[i], max_nums[i-1] + nums[i])
        return max(max_nums)
