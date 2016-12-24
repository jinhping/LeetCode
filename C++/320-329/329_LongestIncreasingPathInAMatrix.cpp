class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> flag;
    int m;
    int n;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        m = matrix.size();
        n = matrix[0].size();
        int ans = 0;
        dp.resize(m, vector<int>(n));
        flag.resize(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = search(i, j, matrix);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;        
    }
    
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    
    int search(int x, int y, vector<vector<int>>& matrix) {
        if (flag[x][y] != 0) {
            return dp[x][y];
        }
        
        int ans = 1;
        int nx, ny;
        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (0 <= nx && nx < m && 0 <= ny && ny < n) {
                if (matrix[x][y] > matrix[nx][ny]) {
                    ans = max(ans, search(nx, ny, matrix) + 1);
                }
            }
        }
        flag[x][y] = 1;
        dp[x][y] = ans;
        return ans;
    }
};