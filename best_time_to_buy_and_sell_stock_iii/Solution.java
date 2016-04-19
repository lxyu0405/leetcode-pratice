public class BTTBandSSIII {
    public int maxProfit(int[] prices) {
        if (prices.length < 2){
            return 0;
        }
        int[] preMaxProfit = new int[prices.length];
        int[] posMaxProfit = new int[prices.length];

        preMaxProfit[0] = 0;
        int curMinPri = prices[0];
        for (int i = 1; i < prices.length; i++){
            curMinPri = prices[i] < curMinPri ? prices[i] : curMinPri;
            int curPro = prices[i] - curMinPri;
            preMaxProfit[i] = preMaxProfit[i-1] > curPro ? preMaxProfit[i-1] : curPro;
        }

        posMaxProfit[prices.length-1] = 0;
        int curMaxPri = prices[prices.length-1];
        for (int i = prices.length-2; i >= 0; i--){
            curMaxPri = prices[i] > curMaxPri ? prices[i] : curMaxPri;
            int curPro = curMaxPri - prices[i];
            posMaxProfit[i] = posMaxProfit[i+1] > curPro ? posMaxProfit[i+1] : curPro;
        }

        int maxPro = preMaxProfit[0] + posMaxProfit[0];
        for (int i = 1; i < prices.length; i++){
            int curPro = preMaxProfit[i] + posMaxProfit[i];
            maxPro = curPro > maxPro ? curPro : maxPro;
        }
        return maxPro;
    }
}
