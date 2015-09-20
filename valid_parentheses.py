class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        cha = {
            ')': '(',
            '}': '{',
            ']': '['
            }
            
        stack = []
        for c in s:
            if c not in cha:
                stack.append(c)
            else:
                if stack:
                    if stack[-1] == cha[c]:
                        stack.pop()
                    else:
                        return False
                else:
                    return False
        if stack:
            return False
        else:
            return True