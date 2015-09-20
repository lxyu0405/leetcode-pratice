class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        ro_cha = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
            }
        res = 0
        
        for i, cha in enumerate(s):
            if i + 1 < len(s) and ro_cha[cha] < ro_cha[s[i+1]]:
                res -= ro_cha[cha]
            else:
                res += ro_cha[cha]
                
        return res