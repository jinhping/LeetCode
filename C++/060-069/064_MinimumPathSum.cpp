class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> results(m, vector<int>(n));
        //initialization
        results[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            results[i][0] = results[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; j++) {
            results[0][j] = results[0][j - 1] + grid[0][j];
        }
        //transition function
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                results[i][j] = min(results[i - 1][j], results[i][j - 1]) + grid[i][j];
            }
        }
        return results[m - 1][n - 1];
    }
};