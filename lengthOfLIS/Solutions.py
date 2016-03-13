class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if nums is None:
            return 0

        result = [1 for x in nums]

        length = len(nums)

        for j in xrange(1,length):
            Aj = nums[j]
            for i in xrange(j):
                Ai = nums[i]
                if Ai <= Aj and result[i] + 1 > result[j]:
                    result[j] = result[i] + 1

        return max(result)