#include <iostream>
#include <vector>
#include <algorithm>

using std::max;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

class Solution {
public:
    int rob(vector<int>& nums){
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> robFirstNums, notRobFirstNums;
        for (int i = 0; i < nums.size()-1; i++) {
            robFirstNums.push_back(nums[i]);
            notRobFirstNums.push_back(nums[i+1]);
        }
        return max(robber(robFirstNums),robber(notRobFirstNums));
    }
    
private:
    int robber(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0],nums[1]);
        }
        vector<int> nthMax(nums);
        int maxVal = max(nums[0],nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            nthMax[i] += getMax(nthMax, 0, i-2);
            if (nthMax[i] > maxVal) {
                maxVal = nthMax[i];
            }
        }
        return  maxVal;
    }
    
    int getMax(vector<int>& nthMax, int start, int end){
        int maxVal = nthMax[start];
        for (int i = start; i <= end; i++) {
            if (nthMax[i] > maxVal) {
                maxVal = nthMax[i];
            }
        }
        return maxVal;
    }
};
