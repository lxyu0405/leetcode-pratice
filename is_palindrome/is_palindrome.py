class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        a, res = x, 0
        while a > 0:
            res = res * 10 + a % 10
            a /= 10
        
        if res == x:
            return True
        else:
            return False