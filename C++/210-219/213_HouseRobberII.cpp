class Solution {
public:
    int robEach(vector<int> v) {
        int pre = 0;
        int cur = 0;
        int res = 0;
        for (auto x : v) {
            res = max(pre + x, cur);
            pre = cur;
            cur = res;
        }
        return res;
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> v1(nums.begin(), nums.end() - 1);
        vector<int> v2(nums.begin() + 1, nums.end());
        return max(robEach(v1), robEach(v2));
    }
};