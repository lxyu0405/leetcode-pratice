class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        result = [x for x in range(amount+1)]
        
        for money in range(1,amount+1):
            cantMake = True
            for coin in coins:
                if coin <= money and result[money-coin] != -1 and result[money-coin] + 1 <= result[money]:
                    cantMake = False
                    result[money] = result[money-coin] + 1
            if cantMake:
                result[money] = -1
                    
        return result[amount]