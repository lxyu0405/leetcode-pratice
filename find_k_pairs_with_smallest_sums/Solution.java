import java.util.*;

/**
 * Created by luxy on 7/12/16.
 */
public class FindKPairswithSmallestSums {
    public List<int[]> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        List<int[]> result = new ArrayList<>();
        if (nums1.length == 0 || nums2.length == 0) return result;
        k = Math.min(k, nums1.length * nums2.length);

        Comparator pairSumComp = new Comparator<int[]>(){
            public int compare(int[] pair1, int[] pair2){
                int sum1 = pair1[0] + pair1[1];
                int sum2 = pair2[0] + pair2[1];
                if (sum1 > sum2){
                    return -1;
                }else{
                    return 1;
                }
            }
        };
        Queue<int[]> priQueue = new PriorityQueue<>(nums1.length * nums2.length, pairSumComp);
        for (int i = 0; i < nums1.length; i++){
            for (int j = 0; j < nums2.length; j++){
                int[] thisPair = new int[] {nums1[i], nums2[j]};
                priQueue.add(thisPair);
            }
        }
        for (int i = 0; i < k; i++){
            result.add(priQueue.poll());
        }
        return result;
    }

}

