import java.util.ArrayList;

/**
 * Created by luxy on 4/20/16.
 */
public class SummaryRanges {
    public List<String> summaryRanges(int[] nums) {
        ArrayList<String> summary = new ArrayList<String>();
        if (nums.length < 1){
            return summary;
        }
        int p1 = 0, p2 = 0;
        while (p2 < nums.length-1){
            if (nums[p2+1] != nums[p2] + 1){
                summary.add(newSummary(nums, p1, p2));
                p1 = p2 + 1;
            }
            p2++;
        }
        summary.add(newSummary(nums, p1, p2));
        return summary;
    }

    public String newSummary(int[] nums, int p1, int p2){
        if (p1 == p2){
            return String.valueOf(nums[p1]);
        }else{
            return String.valueOf(nums[p1]) + "->" + String.valueOf(nums[p2]);
        }
    }
}

