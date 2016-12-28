class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> results(m, vector<int>(n));
        //initialization
        for (int i = 0; i < m; i++) {
            results[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
            results[0][j] = 1;
        }
        //state transition function
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                results[i][j] = results[i - 1][j] + results[i][j - 1];
            }
        }
        //result
        return results[m - 1][n - 1];
        
    }
};