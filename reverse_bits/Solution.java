public class ReverseBits {
    public int reverseBits(int n) {
        int res = 0;
        for (int i = 0; i < 32; i++){
            res <<= 1;
            res |= ((n >> i) & 1);
        }
        return res;
    }
}

