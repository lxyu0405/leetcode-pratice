class Solution(object):
    def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """
        childnum = len(ratings)
        candynum = [1 for i in range(childnum)]
        for i in range(childnum-1):
            if ratings[i+1] > ratings[i]:
                candynum[i+1] = candynum[i] + 1
        for i in reversed(range(1,childnum)):
            if ratings[i-1] > ratings[i] and candynum[i-1] <= candynum[i]:
                candynum[i-1] = candynum[i] + 1
        return sum(candynum)
            
