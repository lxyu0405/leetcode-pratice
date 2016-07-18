#include <iostream>

using namespace std;

class Solution{
public:
    bool canMeasureWater(int x, int y, int z) {
        // x + y == z
        // OR x + y > z && z % gcd(x,y) == 0
        return x + y == z || ((x + y > z) && (z % gcd(x,y) == 0));
    }
    
private:
    int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a%b);
    }
};
