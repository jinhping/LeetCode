class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry == 1) {
            if (i >= 0) {
                carry = carry + (a[i] - '0');
                i--;
            } else {
                carry = carry + 0;
            }
            if (j >= 0) {
                carry = carry + (b[j] - '0');
                j--;
            } else {
                carry = carry + 0;
            }
            res = char(carry % 2 + '0') + res;
            carry = carry / 2;
        }
        return res;
    }
};