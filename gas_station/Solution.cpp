#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res = 0;
        int gasSum = 0;
        int curSum = 0;
        for (int i = 0; i < gas.size(); i++) {
            gasSum += gas[i] - cost[i];
            curSum += gas[i] - cost[i];
            if (curSum < 0) {
                res = i + 1;
                curSum = 0;
            }
        }
        if (gasSum < 0) {
            return -1;
        }
        return res;
    }
};
