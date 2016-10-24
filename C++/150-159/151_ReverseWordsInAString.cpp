class Solution {
public:
    void reverseWords(string &s) {
        int j = s.length();
        string res = "";
        for (int i = s.length() - 1; i >= 0; i-- ) {
            if (s[i] == ' ') {
                j = i;
            }
            else if (i == 0 || s[i - 1] == ' ') {
                if (!res.empty()) {
                    res += " ";
                }
                res += s.substr(i,j-i);
            }
        }
        s = res;
    }
};