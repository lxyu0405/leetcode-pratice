/**
 * Created by luxy on 4/20/16.
 */
public class IntegerBreak {
    public int integerBreak(int n) {
        int[] maxProduct = new int[n+1];
        maxProduct[0] = maxProduct[1] = 1;
        maxProduct[2] = 1;
        for (int i = 3; i <= n; i++){
            for (int j = 1; j <= i/2; j++){
                int pro1 = max(j, maxProduct[j]);
                int pro2 = max(i-j, maxProduct[i-j]);
                maxProduct[i] = max(maxProduct[i], pro1*pro2);
            }
        }
        return maxProduct[n];
    }
    public int max(int a, int b){
        return a > b ? a : b;
    }
}
