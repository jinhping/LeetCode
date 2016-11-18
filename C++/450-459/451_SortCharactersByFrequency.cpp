class Solution {
public:
    string frequencySort(string s) {
        string res = "";
        if (s == "") {
            return res;
        }
        unordered_map<char, int> m;
        for (auto x : s) {
            if (m.find(x) == m.end()) {
                m[x] = 1;
            } else {
                m[x]++;
            }
        }
        map<int, vector<char>> sorted_m;
        for (auto i : m) {
            if (sorted_m.find(i.second) == sorted_m.end()) {
                vector<char> tmp;
                sorted_m[i.second] = tmp;
                sorted_m[i.second].push_back(i.first);
            } else {
                sorted_m[i.second].push_back(i.first);
            }
        }
        for (auto i : sorted_m) {
            int count = i.first;
            for (auto x : i.second) {
                while(count != 0) {
                    res += x;
                    count--;
                }
                count = i.first;
            }
        }
        int i = 0;
        int j = res.length() - 1;
        while (i < j) {
            swap(res[i],res[j]);
            i++;
            j--;
        }
        return res;
    }
};