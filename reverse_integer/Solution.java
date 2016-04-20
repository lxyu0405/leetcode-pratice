/**
 * Created by luxy on 4/20/16.
 */
public class ReverseInteger {
    public int reverse(int x) {
        int flag = x > 0 ? 1 : -1;
        int num = x > 0 ? x : -x;
        long  res = 0;
        while (num > 0){
            res = res * 10 + num % 10;
            num /= 10;
            if (res < Integer.MIN_VALUE || res > Integer.MAX_VALUE){
                return 0;
            }
        }
        return (int)res * flag;
    }
}
