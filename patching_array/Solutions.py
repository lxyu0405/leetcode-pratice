class Solution(object):
    def minPatches(self, nums, n):
        """
        :type nums: List[int]
        :type n: int
        :rtype: int
        """
        frontier = 1

        cnt = 0
        index = 0
        while frontier <= n:
            if index < len(nums) and nums[index] <= frontier:
                frontier += nums[index]
                index += 1
            else:
                frontier <<= 1
                cnt += 1
        return cnt



if __name__ == "__main__":
    nums = [1,2]
    test = Solution()
    print(test.minPatches(nums,4))
