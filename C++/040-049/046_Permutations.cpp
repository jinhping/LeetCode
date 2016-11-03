class Solution {
public:
    void helper(vector<vector<int>> &results, vector<int> &nums, int pos) {
        if (pos == nums.size()) {
            results.push_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            swap(nums[i], nums[pos]);
            helper(results, nums, pos + 1);
            swap(nums[i], nums[pos]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        helper(results, nums, 0);
        return results;
    }
};