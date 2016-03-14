class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return None
        if len(nums) == 1:
            return nums[0]

        left = 0
        right = len(nums)-1

        minimum = nums[0]

        while left < right:
            mid = (left + right) >> 1
            if right == left + 1: # in case of an array doesn't have a pivot
                return min(nums[right],minimum)
            if nums[left] < nums[mid]: # the left side is sorted. So, the min element in right side, including the mid
                minimum = min(minimum,nums[left])
                left = mid
            elif nums[left] > nums[mid]: # the right side is sorted. So, the min element in left side, including the mid
                right = mid
            elif nums[left] == nums[mid]: # nums[left] == nums[mid]
                left += 1



if __name__ == "__main__":
    nums = [1,1]
    test = Solution()
    print(test.findMin(nums))
