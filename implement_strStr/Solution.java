import java.util.ArrayList;
import java.util.List;

/**
 * Created by luxy on 6/18/16.
 * 0    1   2   3   4   5   6   7   8   9
 * a    b   a   b   a   c   b   a   b   c
 * a    b   c
 */

public class ImplementStrStr {
    private List<Integer> next = new ArrayList<Integer>();
    public int strStr(String haystack, String needle) {
        // elegant method
        for (int i = 0; ; i++) {
            for (int j = 0; ; j++) {
                if (j == needle.length()) return i;
                if (i + j == haystack.length()) return -1;
                if (needle.charAt(j) != haystack.charAt(i + j)) break;
            }
        }
    }

    public int strStrKMP(String haystack, String needle){
        preprocess(needle);
        if (needle.length() == 0)   return 0;
        if (haystack.length() == 0) return -1;
        int j = -1;
        for (int i = 0; i < haystack.length(); i++){
            while (j >= 0 && haystack.charAt(i) != needle.charAt(j+1))
                j = next.get(j);
            if (haystack.charAt(i) == needle.charAt(j+1))
                j++;
            if (j == needle.length()-1)
                return i-needle.length()+1;
        }
        return -1;
    }

    private void preprocess(String needle){
        next.add(-1);
        int j = -1;
        for (int i = 1; i < needle.length(); i++){
            while (j >= 0 && needle.charAt(i) != needle.charAt(j+1))
                j = next.get(j);
            if (needle.charAt(i) == needle.charAt(j+1))
                j++;
            next.add(j);
        }
    }

}
