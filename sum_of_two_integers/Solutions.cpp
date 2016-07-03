class Solution {
public:
    int getSum(int a, int b) {
        long temp = (long)a + (long)b;
        if (temp > INT16_MAX) {
            return INT16_MAX;
        }
        if (temp < INT16_MIN) {
            return INT16_MIN;
        }
        return (int)temp;
    }
};
