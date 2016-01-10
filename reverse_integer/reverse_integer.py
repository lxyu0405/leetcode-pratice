class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x == 0:
            return x
        sign = 1
        res = 0
        if x < 0:
            sign = -1
            x = -x
        while x > 0:
            res = res * 10 + x % 10
            x /=10
        if res > 0x7fffffff:
            return 0
        else:
            return res
