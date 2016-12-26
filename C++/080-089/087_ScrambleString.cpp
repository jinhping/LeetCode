class Solution {
public:
    unordered_map<string, bool> m;

    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        
        if (m.find(s1 + "#" + s2) != m.end()) {
            return m[s1 + "#" + s2];
        }
        
        int n = s1.length();
        if (n == 1) {
            return s1[0] == s2[0];
        }
        
        for (int k = 1; k < n; k++) {
            if (isScramble(s1.substr(0, k), s2.substr(0, k)) &&
                isScramble(s1.substr(k, n), s2.substr(k, n)) ||
                isScramble(s1.substr(0, k), s2.substr(n - k, n)) &&
                isScramble(s1.substr(k, n), s2.substr(0, n - k))) {
                m[s1 + "#" + s2] = true;
                return true;
            }
        }
        m[s1 + "#" + s2] = false;  
        return false;        
    }
};