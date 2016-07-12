import java.util.ArrayList;
import java.util.List;

/**
 * Created by luxy on 7/12/16.
 */
public class SuperPow {
    List<Integer> tenBase = new ArrayList<Integer>();
    int MOD_NUM = 1337;
    public int superPow(int a, int[] b) {
        if (b.length == 0)  return 1;
        // b = [x, y, z] => a^(100x + 10y + z)
        calculateTenPowBase(a, b);
        int tempResult = 1;
        for (int i = b.length-1; i >= 0; i--){
            // calculate a^100x or a^10y or a^1z
            // base is a^100 and times is x
            int thisResult = nextTenPowBase(tenBase.get(b.length-1-i), b[i]);
            tempResult *= thisResult;
            tempResult %= MOD_NUM;
        }
        return tempResult;
    }

    // get a^1 a^10 a^100 a^1000
    private void calculateTenPowBase(int a, int[] b){
        int pow_size = b.length;
        int thisTenBase = a % MOD_NUM;
        tenBase.add(thisTenBase);
        for (int i = 1; i < pow_size; i++){
            int nextTenBase = nextTenPowBase(thisTenBase, 10);
            tenBase.add(nextTenBase);
            thisTenBase = nextTenBase;
        }
    }

    private int nextTenPowBase(int thisTenBase, int num){
        // a^10 mod 1337 = (a mod 1337 * a mod 1337 ... ) mod 1337
        int nextTenBase = 1;
        for (int i = 0; i < num; i++){
            nextTenBase *= thisTenBase;
            nextTenBase %= MOD_NUM;
        }
        return nextTenBase;
    }
}

