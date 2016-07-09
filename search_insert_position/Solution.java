public class SearchInsertPosition {
    public int searchInsert(int[] nums, int target) {
        if (nums.length == 0)   return 0;
        int begin_index = 0, end_index = nums.length-1;
        while (begin_index <= end_index){
            int mid = (begin_index + end_index) >> 1;
            if (nums[mid] > target){
                end_index = mid - 1;
            }else if(nums[mid] < target){
                begin_index = mid + 1;
            }else {
                return mid;
            }
        }
        return begin_index;
    }
}

