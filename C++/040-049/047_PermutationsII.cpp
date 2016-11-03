class Solution {
public:
    void helper (vector<int> & nums, vector<vector<int>> & results, vector<int> &solution, vector<int> &visited) {
        if (solution.size() == nums.size()) {
            results.push_back(solution);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] == 1 || (i != 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0)) {
                continue;
            }
            solution.push_back(nums[i]);
            visited[i] = 1;
            helper(nums, results, solution, visited);
            visited[i] = 0;
            solution.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> solution;
        vector<int> visited(nums.size(), 0);
        sort(nums.begin(), nums.end());
        helper(nums, results, solution, visited);
        return results;
    }
};