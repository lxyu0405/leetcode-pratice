#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() < 1) {
            return 0;
        }
        int newLength = 0;
        // find first no-val position
        int validPos = 0;
        bool setValidPos = false;
        int thisPos = 0;
        for (; thisPos < nums.size(); thisPos++) {
            if (nums[thisPos] != val) {
                newLength++;
            }
            if (setValidPos && nums[thisPos] != val) {
                swapValInVector(nums, thisPos, validPos);
                validPos++;
            }
            if ((!setValidPos) && nums[thisPos] == val) {
                validPos = thisPos;
                setValidPos = true;
            }
        }
        return newLength;
    }
private:
    void swapValInVector(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};
