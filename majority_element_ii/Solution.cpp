#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        if (nums.size() == 0) {
            return res;
        }
        if (nums.size() == 1) {
            res.push_back(nums[0]);
            return res;
        }
        int maj1 = 0, maj1Cnt = 0;
        int maj2 = 0, maj2Cnt = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (maj1Cnt == 0 && (maj2Cnt == 0 || maj2 != nums[i])) {
                maj1 = nums[i];
                maj1Cnt = 1;
                continue;
            }
            if (maj2Cnt == 0 && (maj1Cnt == 0 || maj1 != nums[i])) {
                maj2 = nums[i];
                maj2Cnt = 1;
                continue;
            }
            
            if (maj1 == nums[i]) {
                maj1Cnt++;
                continue;
            }
            
            if (maj2 == nums[i]) {
                maj2Cnt++;
                continue;
            }
            maj1Cnt--;
            maj2Cnt--;
        }
        
        int maj1CntSum = 0;
        int maj2CntSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (maj1Cnt != 0 && nums[i] == maj1) {
                maj1CntSum++;
            }
            if (maj2Cnt != 0 && nums[i] == maj2) {
                maj2CntSum++;
            }
        }
        if (maj1CntSum > nums.size()/3) {
            res.push_back(maj1);
        }
        if (maj2CntSum > nums.size()/3) {
            res.push_back(maj2);
        }
        return res;
    }
};

