class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int res = 0;
        int sum = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum == k) {
                res = i + 1;
            }
            else if (m.find(sum - k) != m.end()) {
                res = max(res, i - m[sum - k]);
            }
            if (m.find(sum) == m.end()) {
                m[sum] = i;
            }   
        }
        return res;
    }
};