class Solution {
public:
    void reverse(string &s, int start, int end) {
        while (start < end) {
            char tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
            start++;
            end--;
        }
    }

    //first reverse the entire string
    //second reverse each word in the string
    void reverseWords(string &s) {
        reverse(s, 0, s.length() - 1);
        int start = 0;
        int end = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        reverse(s, start, s.length() - 1);
    }
};