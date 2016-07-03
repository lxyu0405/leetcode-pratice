#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) {
            return true;
        }
        long long lowerBound = 1, upperBound = num;
        // binary search
        while (lowerBound < upperBound-1) {
            long long mid = (lowerBound + upperBound) >> 1;
            long long thisSquare = mid * mid;
            if (thisSquare < num) {
                lowerBound = mid;
            }else if (thisSquare > num){
                upperBound = mid;
            }else{
                return true;
            }
        }
        return false;
    }
};
