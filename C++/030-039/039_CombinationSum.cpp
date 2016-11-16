class Solution {
public:
    void helper(vector<vector<int>> &results, vector<int> &candidates, vector<int> &path, int target, int pos, int sum) {
        if (sum == target) {
            results.push_back(path);
            return;
        }
        for (int i = pos; i < candidates.size() && sum + candidates[i] <= target; i++) {
            path.push_back(candidates[i]);
            sum += candidates[i];
            helper(results, candidates, path, target, i, sum);
            sum -= candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> results;
        vector<int> path;
        helper(results, candidates, path, target, 0, 0);
        return results;
    }
};