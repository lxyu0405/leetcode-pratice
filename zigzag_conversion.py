class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        res = ''
        lens = len(s)
        if lens == 0 or numRows <= 1:
            return s
        main_gap = 2*(numRows - 1)
        for row in range(numRows):
            side_gap, index = 2*(numRows -1 - row), row
            while index < lens:
                res += s[index]
                if row == 0 or row == numRows - 1:
                    pass
                elif index + side_gap < lens:
                    res += s[index+side_gap]
                index += main_gap
        return res