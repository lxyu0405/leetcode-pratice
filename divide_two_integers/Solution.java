public class DivideTwoIntegers {
    public int divide(int dividend, int divisor) {
        return divideLong((long)dividend, (long)divisor);
    }

    private int divideLong(long dividend, long divisor){
        if (dividend == Integer.MIN_VALUE && divisor == -1)
            return Integer.MAX_VALUE;
        if (dividend < 0)
            return -divideLong(-dividend, divisor);
        if (divisor < 0)
            return -divideLong(dividend, -divisor);
        return divideCore(dividend, divisor);
    }
    private int divideCore(long dividend, long divisor){
        if (dividend < divisor)
            return 0;
        long upperBound = divisor;
        long res = 1;
        while (upperBound < dividend){
            upperBound <<= 1;
            res <<= 1;
        }
        if (upperBound == dividend)
            return (int)res;
        long lowerBound = (upperBound >> 1);
        return (int)(res >> 1) + divideCore(dividend - lowerBound, divisor);
    }
}

