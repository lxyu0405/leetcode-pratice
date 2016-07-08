public class CountNumbersWithUniqueDigits {
    public int countNumbersDP(int n) {
        if(n == 0)  return 1;
        // boundary consideration
        n = Math.min(n, 10);
        int[] dp = new int[n+1];
        dp[0] = 1;
        dp[1] = 9;
        // 9*9*8*7*6*5 ...
        for (int i = 2; i <= n; i++){
            dp[i] = dp[i-1] * (11 - i);
        }
        // Get sum
        int res = 0;
        for (int i = 0; i <= n; i++ ){
            res += dp[i];
        }
        return res;
    }
}

