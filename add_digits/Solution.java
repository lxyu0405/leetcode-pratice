public class AddDigits {
    public int Solution1(int num){
        int res = 0;
        while (num > 0){
            res += num % 10;
            num /= 10;
        }
        if (res / 10 > 0){
            return Solution1(res);
        }else{
            return res;
        }
    }

    public int Solution2(int num){
        return (num - 1) % 9 + 1;
    }
}

