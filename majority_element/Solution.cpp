#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() <= 2) {
            return nums[1];
        }
        int majorityNum = nums[0];
        int majorityCnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (majorityNum == nums[i]) {
                majorityCnt++;
            }else{
                // majorityNum != nums[i]
                majorityCnt--;
                if (majorityCnt == 0) {
                    majorityNum = nums[i];
                    majorityCnt = 1;
                }
            }
        }
        return majorityNum;
    }
};
