class Solution {
public:
    int numDecodings(string s) {
        if (s.length() == 0) {
            return 0;
        }
        vector<int> result(s.length() + 1);
        result[0] = 1;
        result[1] = s[0] != '0' ? 1 : 0;
        for (int i = 2; i < s.length() + 1; i++) {
            if (s[i - 1] != '0' ) {
                result[i] = result[i - 1];
            }
            int twoDigits = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
            if (twoDigits >= 10 && twoDigits <= 26) {
                result[i] += result[i - 2];
            }
        }
        return result[s.length()];
    }
};