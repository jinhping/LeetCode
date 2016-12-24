class Solution {
public: 
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> map;
        int j = 0;
        int maxLength = 0;
        for (int i = 0; i < s.length(); i++) {
           while (j < s.length()) {
               if (map.find(s[j]) != map.end()) {
                   map[s[j]]++;
               } else {
                   if (map.size() == k) {
                       break;
                   }
                   map[s[j]] = 1;
               }
               maxLength = max(maxLength, j - i + 1);
               j++;
           }
           
            if (map.find(s[i]) != map.end()) {
                if (map[s[i]] > 1) {
                    map[s[i]]--;
                } else {
                    map.erase(s[i]);
                }        
            }
        }
        return maxLength;
    }
};