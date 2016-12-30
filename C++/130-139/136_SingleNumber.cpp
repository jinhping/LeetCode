class Solution {
public:
    // 0 ^ N = N
    // N ^ N = N
    // use XOR
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto x : nums) {
            res = x ^ res;
        }
        return res;
    }
};