#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> twoSumMap;
        for (int i = 0; i < nums.size(); i++) {
            auto theOne = twoSumMap.find(target-nums[i]);
            if (theOne == twoSumMap.end()) {
                twoSumMap.insert({nums[i],i});
            }else{
                res.push_back(theOne->second);
                res.push_back(i);
                break;
            }
        }
        return res;
    }
};
