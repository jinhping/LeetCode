class Solution {
    public int[] plusOne(int[] digits) {
        int i = digits.length - 1;
        int carry = 0;
        while (i >= 0) {
            if (digits[i] < 9) {
                digits[i] += 1;
                return digits;
            } 
            digits[i] = 0;
            i--;
        }
        int[] res = new int[digits.length + 1];
        res[0] = 1;
        return res;
    }
}