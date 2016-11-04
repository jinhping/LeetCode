class Solution {
public:
    int helper (vector<int> &v) {
        vector<int> tmp(v.size());
        if (v.size() == 1) {
            return v[0];
        }
        if (v.size() == 2) {
            return max(v[0], v[1]);
        }
        tmp[0] = v[0];
        tmp[1] = max(v[0], v[1]);
        for (int i = 2; i < v.size(); i++) {
            tmp[i] = max(tmp[i - 2] + v[i], tmp[i - 1]);
        }
        return tmp[v.size() - 1];
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
        return max(helper(v1), helper(v2));
    }
};