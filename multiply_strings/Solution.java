public class MultiplyStrings {
    public String multiply(String num1, String num2) {
        // make sure num1.length() > num2.length()
        if(num1.length() < num2.length()){
            return multiply(num2, num1);
        }
        // zero case
        if ((num2.length() == 1 && num2.charAt(0) == '0') || (num1.length() == 1 && num1.charAt(0) == '0')){
            return "0";
        }

        int max_length = num1.length();
        int[] number1 = new int[num1.length()];
        int[] number2 = new int[num2.length()];
        int[] result = new int[max_length * 2];
        // split each char into the array
        for (int i = 0; i < num1.length(); i++) {
            number1[i] = num1.charAt(num1.length()-i-1) - '0';
        }
        for (int i = 0; i < num2.length(); i++) {
            number2[i] = num2.charAt(num2.length()-i-1) - '0';
        }

        // calculation
        for (int i = 0; i < num2.length(); i++){
            for (int j = 0; j < num1.length(); j++){
                result[i+j] += (number1[j] * number2[i]);
            }
        }

        // get real result
        int carry = 0;
        for (int i = 0; i < 2 * max_length; i++){
            int temp = result[i] + carry;
            result[i] = temp % 10;
            carry = temp / 10;
        }
        // get the begin index
        int begin_index = 2 * max_length - 1;
        while (result[begin_index] == 0){
            begin_index--;
        }

        String res = "";
        for (int i = begin_index; i >= 0; i--){
            res += String.valueOf(result[i]);
        }
        return res;
    }
}

