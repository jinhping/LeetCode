class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> result (s.length() + 1, false);
        result[0] = true;
        for (unsigned long i = 0; i < s.length(); i++) {
            for (int j = i; j >= 0; j--) {
                if (result[j] && wordDict.count(s.substr(j,i-j+1))!=0) {
                    result[i + 1] = true;
                    break;
                }
            }
        }
        return result[s.size()];
    }
};