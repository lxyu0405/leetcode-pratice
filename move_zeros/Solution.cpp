#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() < 2) {
            return;
        }
        // find first no-zero position
        int validPos = 0;
        bool setValidPos = false;
        int thisPos = 0;
        for (; thisPos < nums.size(); thisPos++) {
            if (setValidPos && nums[thisPos] != 0) {
                swapValInVector(nums, thisPos, validPos);
                validPos++;
            }
            if ((!setValidPos) && nums[thisPos] == 0) {
                validPos = thisPos;
                setValidPos = true;
            }
        }
    }
private:
    void swapValInVector(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};
