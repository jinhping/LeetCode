class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> results(m, vector<int>(n));
        //initialization
        bool exist = false;
        for (int i = 0; i < m; i++) {
            if (exist == false && obstacleGrid[i][0] == 0) {
                results[i][0] = 1;
            } else {
                exist = true;
                results[i][0] = 0;
            }
        }
        exist = false;
        for (int j = 0; j < n; j++) {
            if (exist == false && obstacleGrid[0][j] == 0) {
                results[0][j] = 1;
            } else {
                exist = true;
                results[0][j] = 0;
            }
        }
        //state transition function
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    results[i][j] = 0;
                } else {
                   results[i][j] = results[i - 1][j] + results[i][j - 1]; 
                }
            }
        }
        //result
        return results[m - 1][n - 1];
        
    }
};