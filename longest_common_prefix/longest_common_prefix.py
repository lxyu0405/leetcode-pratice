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
            #n_pre, n_s = len(common_prefix), len(s)
            max = len(common_prefix) if len(common_prefix) <= len(s) else len(s)
            temp = ''
            for i in range(len(s)):
                if i < max and s[i] == common_prefix[i]:
                    temp += s[i]
                else:
                    break
            common_prefix = temp
        return common_prefix
