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
            # print(str(left) + " -> " + str(right))
            mid = (left + right) >> 1
            if nums[left] < nums[mid]: # the left side is sorted. So, the min element in right side
                left = mid
            if nums[left] > nums[mid]:
                right = mid
            if right == left + 1: # In case of an array doesn't have a pivot
                return min(nums[right],minimum)


if __name__ == "__main__":
    nums = [1,2]
    test = Solution()
    print(test.findMin(nums))
