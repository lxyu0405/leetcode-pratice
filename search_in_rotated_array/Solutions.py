class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        left = 0
        right = len(nums)-1

        while left <= right:
            mid = (left + right) >> 1
            if nums[mid] == target:
                return mid

            if nums[left] <= nums[mid]:      # left side is sorted
                if nums[left] <= target and target <= nums[mid]:    # in left side
                    right = mid - 1
                else:
                    left = mid + 1
            if nums[mid] < nums[right]:     # right side is sorted
                if nums[mid] <= target and target <= nums[right]:   # in right side
                    left = mid + 1
                else:
                    right = mid - 1

        return -1



if __name__ == "__main__":
    nums = [1]
    test = Solution()
    print("0: " + str(test.search(nums,0)))

