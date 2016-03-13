import heapq

DEBUG = 0

class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        print("Recursive Method: " + str(self.quickSelectRec(nums,k)))
        print("Non-Recursive Method: " + str(self.quickSelectNonRec(nums,k)))
        print("Heap Method: " + str(self.heapSelect(nums,k)))


    # Recursive Method
    def quickSelectRec(self, nums, k):
        pivot = nums[0]
        # create new lists could exceed memory limit
        left = [x for x in nums[1:] if x > pivot]
        right = [x for x in nums[1:] if x <= pivot]
        if len(left) == k-1:
            return pivot
        elif len(left) > k-1:
            return self.quickSelectRec(left,k)
        else:
            return self.quickSelectRec(right,k-1-len(left))

    # Non-Recursive Method
    def quickSelectNonRec(self, nums, k):
        left = 0
        right = len(nums) - 1
        while left <= right:
            pivot_index = self.partition(nums, left, right)
            if pivot_index == k-1:
                return nums[pivot_index]
            elif pivot_index > k-1:
                right = pivot_index-1
            else:
                left = pivot_index+1

        if DEBUG:
            return "Non-Recursive Method"

    def partition(self, nums, left, right):
        i = left-1
        for j in xrange(left,right):
            if nums[j] > nums[right]:
                i += 1
                nums[i], nums[j] = nums[j], nums[i]
            if DEBUG:
                print("\n" + str(j) + "'s round, i: " + str(i) + ", j: " + str(j))
                print(nums)
        nums[i+1], nums[right] = nums[right], nums[i+1]
        return i+1

    # Heap Method
    def heapSelect(self, nums, k):
        reversed_nums = [-x for x in nums]
        heapq.heapify(reversed_nums)

        res = 0
        for i in range(k):
            res = heapq.heappop(reversed_nums)
        return -res

if __name__ == "__main__":
    nums = [3,2,1,5,6,4]
    test = Solution()
    test.findKthLargest(nums,3)


