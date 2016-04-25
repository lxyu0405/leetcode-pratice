#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        while(num > 1){
            if((num & 1) != 0 || (num & 2) != 0){
                return false;
            }
            num >>= 2;
        }
        return num == 1 ? true : false;
    }
    bool isPowerOfFourNoLoops(int num) {
        return (num & (num-1)) == 0 && ((num & 0xAAAAAAAA) == 0) && num > 0;
    }

};
