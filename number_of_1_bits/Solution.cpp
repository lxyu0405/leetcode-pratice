#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Solution {
public:
    int hammingWeight1(uint32_t n) {
        int numof1Bits = 0;
        while (n > 0) {
            if (n & 1) {
                numof1Bits++;
            }
            n >>= 1;
        }
        
        return numof1Bits;
    }
    
    int hammingWeight2(uint32_t n){
        int numof1Bits = 0;
        for (numof1Bits = 0; n; n >>= 1) {
            numof1Bits += n & 1;
        }
        return numof1Bits;
    }
    
    int hammingWeight3(uint32_t n){
        int numof1Bits = 0;
        for (numof1Bits = 0; n; numof1Bits++) {
            n &= (n-1);
        }
        return numof1Bits;
    }
    
};
