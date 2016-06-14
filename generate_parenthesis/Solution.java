import java.util.ArrayList;
import java.util.List;

/**
 * Created by luxy on 6/14/16.
 */
public class GenerateParentheses {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<String>();
        if (n <= 0){
            return res;
        }
        generateCore(res, "(", n-1, n);
        return res;
    }

    private void generateCore(List<String> res, String preRes, int left, int right){
        if (left == 0 && right == 0){
            res.add(preRes);
        }
        if (left > 0){
            generateCore(res, preRes + "(", left-1, right);
        }
        if (right > left){
            generateCore(res, preRes + ")", left, right-1);
        }
    }
}

