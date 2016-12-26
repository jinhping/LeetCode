class Solution {
public:
    void helper(vector<vector<int>> &results, vector<int> &nums, vector<int> &path, int pos) {
        results.push_back(path);
        for (int i = pos; i < nums.size(); i++) {
            path.push_back(nums[i]);
            helper(results, nums, path, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> path;
        helper(results, nums, path, 0);
        return results;
    }
};