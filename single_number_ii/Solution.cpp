#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        size_t intLen = 8 * sizeof(int);
        int res = 0;
        for (size_t i = 0; i < intLen; i++) {
            int cnt = 0;
            for (auto num : nums) {
                if ((num >> i) & 1) {
                    cnt++;
                }
            }
            res |= ((cnt % 3) << i);
        }
        return res;
    }
};
