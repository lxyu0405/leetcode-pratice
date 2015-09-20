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
        
        limit = len(s)
        i = 0
        while i < limit:
            p1 = s[i]
            if i + 1 < len(s):
                p2 = s[i+1]
                if ro_cha[p1] < ro_cha[p2]:
                    res += (ro_cha[p2] - ro_cha[p1])
                    i += 1
                    
                else:
                    res += ro_cha[p1]
                    
            else:
                res += ro_cha[p1]
            
            i += 1

        return res