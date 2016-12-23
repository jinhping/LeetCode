class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        vector<bool> v(256, false);
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            while (j < s.length() && v[s[j]] == false) {
                v[s[j]] = true;
                ans = max(ans, j - i + 1);
                j++;
            }
            v[s[i]] = false;
        }
        return ans;
    }
};