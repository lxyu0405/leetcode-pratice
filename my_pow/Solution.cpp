class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            n = -n;
            x = 1.0/x;
        }
        double res = 1.0;
        for (double f = x; n > 0; n >>= 1) {
            if (n & 1) {
                res *= f;
            }
            f *= f;
        }
        return res;
    }
};
