class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) == 0:
            return ''
            
        common_prefix = strs[0]
        for s in strs[1:]:
            n_pre = len(common_prefix)
            n_s = len(s)
            max = n_pre if n_pre <= n_s else n_s
            temp = ''
            for i in range(n_s):
                if i < max and s[i] == common_prefix[i]:
                    temp += s[i]
                else:
                    break
            common_prefix = temp
        return common_prefix