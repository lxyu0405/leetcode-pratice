import java.util.ArrayList;

/**
 * Created by luxy on 4/18/16.
 */
public class NumArray {
    private ArrayList<Integer> numArray = new ArrayList<Integer>();
    public NumArray(int[] nums) {
        numArray.add(0);
        for (int i = 0; i < nums.length; i++){
            int preNum = numArray.get(i);
            numArray.add(nums[i] + preNum);
        }
    }

    public int sumRange(int i, int j) {
        return numArray.get(j+1) - numArray.get(i);
    }
}

// Your NumArray object will be instantiated and called as such:
// NumArray numArray = new NumArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
