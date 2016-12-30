class Solution {
public:
    string reverseString(string s) {
        int length = s.length();
        if (length <= 1) {
            return s;
        }
        int i = 0;
        int j = length - 1;
        while (i < j) {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
        }
        return s;
    }
};