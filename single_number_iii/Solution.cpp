#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorAll = 0;
        for (auto num : nums) {
            xorAll ^= num;
        }
        int bitIndex = (xorAll & (xorAll - 1)) ^ xorAll;
        // divide nums into two groups
        int res1 = 0, res2 = 0;
        for (auto num : nums) {
            if (num & bitIndex) {
                res1 ^= num;
            }else{
                res2 ^= num;
            }
        }
        
        vector<int> res;
        res.push_back(res1);
        res.push_back(res2);
        
        return res;
    }
};

