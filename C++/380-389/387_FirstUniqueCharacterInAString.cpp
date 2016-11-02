class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for (auto x : s) {
            if (m.find(x) != m.end()) {
                m[x]++;
            } else {
                m[x] = 1;
            }
        }
        for (int i = 0; i < s.length(); i++) {
            if (m[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};