//Solution 1:
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

//Solution 2：
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0 && haystack.length() == 0) return 0;
        if (needle.length() == 0 &&  haystack.length() != 0) return 0;
        if (needle.length() != 0 &&  haystack.length() == 0) return -1;
    
        for (int i = 0; i < haystack.size(); i++) {
            char first = needle[0];
            if (first == haystack[i]) {
                int index = i;
                int j = 0;
                while (i + needle.size() <= haystack.size() && index < haystack.size() && j < needle.size()) {
                    if (haystack[index] != needle[j]) {
                        break;
                    } else {
                        if (j == needle.size() - 1) {
                            return index - j;
                        }
                        index++;
                        j++;
                    }
                }
            }
        }
        return -1;
    }
};