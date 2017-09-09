class Solution {
    public int numDecodings(String s) {
        if (s == null || s.length() == 0) return 0;
        int[] res = new int[s.length() + 1];
        res[0] = 1;
        res[1] = s.charAt(0) != '0' ? 1 : 0; 
        for (int i = 2; i < s.length() + 1; i++) {
            if (s.charAt(i - 1) != '0') {
                res[i] = res[i - 1];
            }
            int twoDigits = Integer.valueOf(s.substring(i - 2, i));
            if (twoDigits >= 10 && twoDigits <= 26) {
                res[i] += res[i - 2];
            }
        }
        return res[s.length()];
    }
}