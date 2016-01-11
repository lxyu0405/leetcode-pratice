
class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead
        """
        n = len(nums)
        k = k % n

        if nums is None or k < 0:
            return
      
        self.reverse(nums, 0, n-1)
        self.reverse(nums, 0, k-1)
        self.reverse(nums, k, n-1)


    def reverse(self, nums, stat, end):
        while stat < end:
            nums[stat], nums[end] = nums[end], nums[stat]
            stat += 1
            end -= 1



test_list = [1,2,3,4,5,6,7]
s = Solution()
s.rotate(test_list,3)

print(test_list)



