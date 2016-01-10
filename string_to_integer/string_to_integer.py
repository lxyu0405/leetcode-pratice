class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int INT_MAX = 2147483647  INT_MIN = -2147483648
        """
        if str is None:
            return 0
        if len(str) == 0:
            return 0
            
        INT_MAX = 2147483647
        INT_MIN = -2147483648
        
        res = 0
        sign = 0
        index = 0
        len_str = len(str)
        
        while index < len_str:
            c = str[index]
            if c == ' ' and sign == 0:
                pass
            elif c == '+' and sign == 0:
                sign += 1
            elif c == '-' and sign == 0:
                sign -= 1
            elif c.isdigit():
                if sign == 0:
                    sign = 1
                res = res * 10 + int(c)
            else:
                break
            
            index += 1
        
        res *= sign
        if res >= INT_MAX:
            return INT_MAX
        elif res <= INT_MIN:
            return INT_MIN
        else:
            return res