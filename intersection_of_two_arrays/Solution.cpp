#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> numsInNums1(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto num : nums2) {
            if (numsInNums1.count(num)) {
                res.push_back(num);
                numsInNums1.erase(num);
            }
        }
        return res;
    }
};
