public class BTTBandSSII {
    public int maxProfit(int[] prices) {
        int maxPro = 0;
        for (int i = 0; i < prices.length - 1; i++){
            int potentialPro = prices[i+1] - prices[i];
            maxPro += potentialPro > 0 ? potentialPro : 0;
        }
        return maxPro;
    }
}
