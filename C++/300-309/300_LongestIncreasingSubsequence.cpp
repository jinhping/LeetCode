class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return 1;
        }
        vector<int> T(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (T[i] < T[j] + 1) {
                        T[i] = T[j] + 1;
                    }
                }
            }
        }
        int max = 0;
        for (auto x : T) {
            if (max < x) {
                max = x;
            }
        }
        return max;
    }
};