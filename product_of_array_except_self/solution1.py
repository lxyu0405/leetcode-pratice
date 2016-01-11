class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        result = []
        
        all_product = 1
        for num in nums:
            all_product *= num
        
        for i,num in enumerate(nums):
            if num == 0:
                result.append(self.product(nums,i))
            else:
                result.append(all_product/num)
        
        return result
    
    def product(self, nums, index):
        result = 1
        for i,num in enumerate(nums):
            if index != i:
                result *= num
        return result