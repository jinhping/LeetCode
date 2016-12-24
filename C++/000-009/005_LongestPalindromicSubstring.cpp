class Solution {
public:
    //check even 
    //check odd
    string longestPalindrome(string s) {
        int size = s.length();
        if (size == 0) {
            return "";
        }
        if (size == 1) {
            return s;
        }
        int maxLength = 1;
        int start = 0;
        for (int i = 1; i < s.length(); i++) {
            //check even 
            int low = i - 1;
            int high = i;
            while (low >= 0 && high <= size - 1 && s[low] == s[high]) {
                if (high - low + 1 > maxLength) {
                    start = low;
                    maxLength = high - low + 1;
                }
                low--;
                high++;
            }
            
            //check odd
            low = i - 1;
            high = i + 1;
            while (low >= 0 && high <= size - 1 && s[low] == s[high]) {
                if (high - low + 1 > maxLength) {
                    start = low;
                    maxLength = high - low + 1;
                }
                low--;
                high++;
            }
        }
        string result = s.substr(start, maxLength);
        return result;
    }
};