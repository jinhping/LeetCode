class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> f(nums.size());
        int max = 0;
        for (int i = 0; i < nums.size(); i++) {
            f[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (f[i] < f[j] + 1) {
                        f[i] = f[j] + 1;
                    }
                }
            }
           if (max < f[i]) {
               max = f[i];
           }
        }
        return max;
    }
};