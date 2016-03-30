#include <iostream>
#include <vector>
#include <algorithm>

using std::min;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNumbers(n,1);
        if (n <= 0) {
            return -1;
        }
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; i++) {
            int times2 = uglyNumbers[p2] << 1;
            int times3 = (uglyNumbers[p3] << 1) + uglyNumbers[p3];
            int times5 = (uglyNumbers[p5] << 2) + uglyNumbers[p5];
            uglyNumbers[i] = min(times2,min(times3,times5));
            if (uglyNumbers[i] == times2) {
                p2++;
            }
            if (uglyNumbers[i] == times3) {
                p3++;
            }
            if (uglyNumbers[i] == times5) {
                p5++;
            }
        }
        return uglyNumbers[n-1];
    }
};

int main(int argc, const char * argv[]) {
    Solution test;
    cout << test.nthUglyNumber(1600) << endl;
    return 0;
}


class Solution_NotGood {
public:
    long nthUglyNumber(int n) {
        vector<long> uglyNumber(n,1);
        if (n <= 0) {
            return -1;
        }
        
        for (int i = 1; i < n; i++) {
            long preUgly = uglyNumber[i-1];
            long thisMin = -1;
            for (int j = 0; j < i; j++) {
                
                
            }
            for (int j = 0; j < i; j++) {
                long thisPoss = (uglyNumber[j] << 1) + uglyNumber[j];
                if (thisPoss > preUgly && thisPoss < thisMin) {
                    thisMin = thisPoss;
                    break;
                }
            }
            for (int j = 0; j < i; j++) {
                long thisPoss = (uglyNumber[j] << 2) + uglyNumber[j];
                if (thisPoss > preUgly && thisPoss < thisMin) {
                    thisMin = thisPoss;
                    break;
                }
            }
            uglyNumber[i] = thisMin;
        }
        return uglyNumber[n-1];
    }
};

