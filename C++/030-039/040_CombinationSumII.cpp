class Solution {
public:
    void helper(vector<vector<int>> &results, vector<int> &candidates, vector<int> &path, int target, vector<int> &visited, int pos, int sum) {
        if (sum == target) {
            results.push_back(path);
            return;
        }
        for (int i = pos; i < candidates.size() && sum < target; i++) {
            if (visited[i] == 1 || (i != 0 && candidates[i] == candidates[i - 1] && visited[i - 1] == 0) ) {
                continue;
            }
            sum += candidates[i];
            visited[i] = 1;
            path.push_back(candidates[i]);
            helper(results, candidates, path, target, visited, i + 1, sum);
            sum -= candidates[i];
            visited[i] = 0;
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        vector<int> visited(candidates.size(), 0);
        helper(results, candidates, path, target,visited, 0, 0);
        return results;
    }
};