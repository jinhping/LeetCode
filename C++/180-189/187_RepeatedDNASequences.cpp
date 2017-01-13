class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> set;
        unordered_set<string> set2;
        vector<string> res;
        for (int i = 0; i < s.length(); i++) {
            string tmp = s.substr(i, 10);
            if (set.find(tmp) != set.end()) {
                set2.insert(tmp);
            } else {
                set.insert(tmp);
            }
        }
        for (auto x : set2) {
            res.push_back(x);
        }
        return res;
    }
};