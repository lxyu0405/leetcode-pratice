/*Find the continous subarray within an array 
 (containing at least one number) which has the largest product.
 
 For example, given the array [2,3,-2,4],
 the contiguous subarray [2,3] has the largest product = 6
 */

#include <stdio.h>
#include <vector>
#include <iostream>

using std::vector;

using std::cin;
using std::cout;
using std::endl;

#define DEBUG 0

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if (!len) return 0;
        if (len == 1) return nums[0];
        
        vector<int> max_product(len,INT16_MIN);
        vector<int> min_product(len,INT16_MAX);
        
        int max_res = nums[0];
        
        max_product[0] = min_product[0] = nums[0];
        
        for (int i=1; i < len; i++) {
            int times_max = max_product[i-1] * nums[i];
            int times_min = min_product[i-1] * nums[i];
            // 需要考虑最大和最小，因为负值可能会在下一次乘积中变成最大 
            max_product[i] = times_max > times_min ? times_max : times_min;
            min_product[i] = times_max > times_min ? times_min : times_max;
            max_product[i] = max_product[i] > nums[i] ? max_product[i] : nums[i];
            min_product[i] = min_product[i] > nums[i] ? nums[i] : min_product[i];
            
            max_res = max_res > max_product[i] ? max_res : max_product[i];
            
            if (DEBUG)
                cout << max_product[i] << " (max) vs (min) " << min_product[i] <<endl;
        }
        
        return max_res;
    }
};


int main(){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(-2);
    nums.push_back(4);
    
    Solution test;
    cout << "The max subarray product is: " << test.maxProduct(nums) << endl;
}


