class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(strs[i]);
        }
        vector<vector<string>> results;
        for (auto x: m) {
            vector<string> tmp2(x.second.begin(), x.second.end());
            results.push_back(tmp2);
        }
        return results;
    }
};