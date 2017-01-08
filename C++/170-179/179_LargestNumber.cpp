class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> res;
        for (auto i : nums) {
             res.push_back(to_string(i));
        }
        sort(res.begin(), res.end(), [](string &s1, string &s2){ return s1 + s2 > s2 + s1;});
        string num;
        for (auto x : res) {
            num += x;
        }
        while(num[0] == '0' && num.length() > 1) {
            num.erase(0,1);
        }
        return num;
    }
};