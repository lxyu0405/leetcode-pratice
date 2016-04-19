package leetcode;

/**
 * Created by luxy on 4/18/16.
 */
// Best Time to Buy and Sell Stock with Cooldown
public class BTTBandSSWithCooldown {

    // Time Limit Exceeded
    /*
    public int maxProfit(int[] prices) {
        int len = prices.length;
        if (len < 2){
            return 0;
        }
        int[] maxProfit = new int[len];
        maxProfit[0] = 0;
        maxProfit[1] = prices[1] - prices[0] > 0 ? prices[1] - prices[0] : 0;
        for (int i = 2; i < len; i++){
            int thisCoolDownPro = maxProfit[i-1];
            int preCoolDownPro = maxProfit[i-2];
            int prePreCoolDownPro = maxProfit[i-3] + (prices[i] - prices[i-1] > 0 ? prices[i] - prices[i-1] : 0);
            int noCoolDownPro = prices[i] - rangeMin(prices, 0, i) > 0 ? prices[i] - rangeMin(prices, 0, i) : 0;
            maxProfit[i] = max(thisCoolDownPro, max(preCoolDownPro, max(prePreCoolDownPro, noCoolDownPro)));
        }
        return maxProfit[len-1];
    }

    public int rangeMin(int[] prices, int begin, int end){
        int minPri = prices[begin];
        for (int i = begin; i <= end; i++){
            minPri = prices[i] < minPri ? prices[i] : minPri;
        }
        return minPri;
    }*/

    public int max(int a, int b){
        return a > b ? a : b;
    }
    public int maxProfit(int[] prices){
        if (prices.length < 2){
            return 0;
        }
        // S0: rest(S0), buy(S1)
        // S1: rest(S1), sell(S2)
        // S2: rest(S0)
        int[] s0 = new int[prices.length];
        int[] s1 = new int[prices.length];
        int[] s2 = new int[prices.length];
        s0[0] = 0;
        s1[0] = -prices[0];
        s2[0] = 0;
        for (int i = 1; i < prices.length; i++){
            s0[i] = max(s0[i-1], s2[i-1]);
            s1[i] = max(s1[i-1], s0[i-1] - prices[i]);
            s2[i] = s1[i-1] + prices[i];
        }
        return max(s0[prices.length-1], s2[prices.length-1]);
    }
}

