class Solution {
public:
    int strStr(string haystack, string needle) {
        int length_needle = needle.length();
        int length_haystack = haystack.length();
        if (length_needle > length_haystack) {
            return -1;
        }
        if (length_needle == 0) {
            return 0;
        }
        int lastIndexPos = length_haystack - length_needle;
        for (int i = 0; i <= lastIndexPos; i++) {
            if (haystack[i] == needle[0]) {
                string tmp = haystack.substr(i, length_needle);
                if (tmp == needle ) {
                    return i;
                }
            }
        }
        return -1;
    }
};