class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        for (char now : t) {
            m[now] ++;
        }
        int count = m.size();
        int j = 0;
        int ans = INT_MAX;
        string res; 
        for (int i = 0; i < s.size(); i++) {
            while(count != 0 && j < s.size()) {
                m[s[j]]--;
                if (m[s[j]] == 0) {
                    count--;
                }
                j++;
                if (count == 0) {
                    break;
                }
            }
            if (count == 0 && j - i< ans) {
                ans = j - i;
                res = s.substr(i, j - i);
                
            }
            if(m[s[i]] == 0) {
                count++;
            }
            m[s[i]]++;
        }
        return res;
    }
};