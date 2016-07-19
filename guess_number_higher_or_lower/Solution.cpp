#include <iostream>

using namespace std;

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long lowerBound = 1, upperBound = n;
        while(1){
            long long mid = (lowerBound + upperBound) >> 1;
            int res = guess(mid);
            if(res == 0){
                return (int)mid;
            }else if(res == -1){
                // number is lower
                upperBound = mid - 1;
            }else{
                // number is higher
                lowerBound = mid + 1;
            }
        }
    }
};
