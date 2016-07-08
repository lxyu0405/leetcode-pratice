public class MissingNumber {
    public int missingNumberSum(int[] nums) {
        // origin sum last element
        int originSum = nums.length;
        int realSum = 0;
        for (int i = 0; i < nums.length; i++) {
            originSum += i;
            realSum += nums[i];
        }
        // the gap is the missing number
        return originSum - realSum;
    }
    public int missingNumberBit(int[] nums) {
        int originXOR = nums.length;
        int realXOR = 0;
        for (int i = 0; i < nums.length; i++){
            originXOR ^= i;
            realXOR ^= nums[i];
        }
        // realXOR ^ X = originXOR ==> x = realXOR ^ xoriginXOR
        return originXOR ^ realXOR;
    }
}

