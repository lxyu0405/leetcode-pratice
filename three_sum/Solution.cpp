#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) {
            return res;
        }
        
        int target = 0;
        sort(nums.begin(), nums.end());
        bool startCheckPre = false;
        int preNum = 0;
        
        for (int i = 0; i < nums.size() - 2; i++) {
            // skip duplicates
            if (startCheckPre && nums[i] == preNum) {
                continue;
            }
            // two sum target
            int twoSumTarget = target - nums[i];
            // two pointers
            int start = i + 1, end = nums.size() - 1;
            // remove duplicates
            bool checkPre = false;
            int preStart = 0, preEnd = 0;
            while (start < end) {
                if (checkPre && nums[start] == preStart && nums[end] == preEnd && preStart + preEnd == twoSumTarget) {
                    start++;
                    end--;
                    continue;
                }
                // remember pre values
                checkPre = true;
                preStart = nums[start];
                preEnd = nums[end];
                
                int thisSum = nums[start] + nums[end];
                if (thisSum < twoSumTarget) {
                    start++;
                }else if (thisSum > twoSumTarget){
                    end--;
                }else{
                    // thisSum == twoSumTarget
                    vector<int> thisRes;
                    thisRes.push_back(nums[i]);
                    thisRes.push_back(nums[start]);
                    thisRes.push_back(nums[end]);
                    res.push_back(thisRes);
                    start++;
                    end--;
                }
            }
            // remember pre valu
            startCheckPre = true;
            preNum = nums[i];
        }
        return res;
    }
};
