public class BTTBandSS {
    public int maxProfit(int[] prices) {
        if (prices.length <= 1){
            return 0;
        }
        int minPrices = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.length; i++){
            minPrices = prices[i] < minPrices ? prices[i] : minPrices;
            maxProfit = (prices[i] - minPrices) > maxProfit ? (prices[i] - minPrices) : maxProfit;
        }
        return maxProfit;
    }
}
