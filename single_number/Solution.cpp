#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto num : nums) {
            res ^= num;
        }
        return res;
    }
};
