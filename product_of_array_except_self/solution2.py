class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        res = [1 for i in range(n)]

        # from left to right
        for i in range(1,n): # 1 ~ n-1
            res[i] = res[i-1] * nums[i-1]

        # from right to left
        right_product = 1
        for i in range(1,n): # 1 ~ n-1
            j = n - 1 - i    # 0 ~ n-2
            right_product *= nums[j+1]
            res[j] *= right_product

        return res


l1 = [1,2,3,4,5]
s = Solution()
print(s.productExceptSelf(l1))


