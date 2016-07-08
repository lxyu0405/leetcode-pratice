import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created by luxy on 7/8/16.
 */
public class IntersectionofTwoArrayII {
    public int[] intersect(int[] nums1, int[] nums2) {
        // arrange the data into array
        Map<Integer, Integer> recMap = new HashMap<Integer, Integer>();
        for (int num : nums1){
            if (recMap.containsKey(num)){
                recMap.put(num, recMap.get(num)+1);
            }else{
                recMap.put(num, 1);
            }
        }
        // find intersection
        List<Integer> tempRes = new ArrayList<Integer>();
        for (int num : nums2){
            if (recMap.containsKey(num) && recMap.get(num) > 0){
                tempRes.add(num);
                recMap.put(num, recMap.get(num)-1);
            }
        }
        // transform arraylist to array
        int[] result = new int[tempRes.size()];
        for (int i = 0; i < tempRes.size(); i++){
            result[i] = tempRes.get(i);
        }
        return result;
    }
}

