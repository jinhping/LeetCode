class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        int rob = nums[0];
        int unrob = 0;
        vector<int> res(nums.size());
        res[0] = rob;
        res[1] = max(nums[1], nums[0]);
        for (int i = 2; i < nums.size(); i++) {
           res[i] = max(res[i - 1], res[i - 2] + nums[i]); 
        }
        return res[nums.size() - 1];
    }
};