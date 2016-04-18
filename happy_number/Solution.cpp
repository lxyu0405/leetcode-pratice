#include <iostream>
#include <vector>
#include <set>

using namespace std;


class Solution {
public:
    bool isHappy(int n) {
        set<int> nums;
        while (1) {
            int thisSquare = digitsSquare(n);
            if (thisSquare == 1) {
                return true;
            }
            if (nums.count(thisSquare) >= 1) {
                return false;
            }
            nums.insert(thisSquare);
            n = thisSquare;
        }
    }
    
    int digitsSquare(int n){
        int res = 0;
        while (n > 0) {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        return res;
    }
};

