#include <vector>
#include <string>
#include <math.h>
#include <iostream>

using namespace std;


class Solution {
public:
    int countPrimes(int n) {
        if (n < 3){
            return 0;
        }
        vector<int> primes(n, true);
        primes[0] = primes[1] = false;
        for (int i = 0; i < sqrt(n); i++) {
            if (primes[i]) {
                for (int j = i * i; j < n; j += i) {
                    primes[j] = false;
                }
            }
        }
        return count(primes.begin(), primes.end(), true);
    }
};
