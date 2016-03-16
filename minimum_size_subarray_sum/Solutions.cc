#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::vector;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        if (!len) {
            return 0;
        }
        
        int left = 0, right = 0, min_length = INT16_MAX, sum = 0;
        while (right < len) {
            while (sum < s && right < len) {
                sum += nums[right++];
            }
            while (sum >= s) {
                int curr_length = right - left;
                min_length = min_length < curr_length ? min_length : curr_length;
                sum -= nums[left++];
            }
        }
        return min_length > len ? 0 : min_length;
    }
};

int main(){
    Solution test;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    
    cout << "The minimum size is: " << test.minSubArrayLen(11,nums) << endl;
}

