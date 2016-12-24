//Solution 1, then I will use a rolling array 滚动数组 to improve the space 
//since we do not necessary to keep all the states every updates.
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return 0;
        }
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (matrix[i - 1][j - 1] == '0') {
                    f[i][j] = 0;
                } else {
                    f[i][j] = min(min(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1]) + 1;
                    ans = max(ans, f[i][j]);
                }
            }
        }
        return ans * ans;       
    }
};

//Solution 2 using 滚动数组 to improve space complexity.
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return 0;
        }
        vector<vector<int>> f(2, vector<int>(n + 1));
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (matrix[i - 1][j - 1] == '0') {
                    f[i % 2][j] = 0;
                } else {
                    f[i % 2][j] = min(min(f[(i - 1) % 2][j], f[i % 2][j - 1]), f[(i - 1) % 2][j - 1]) + 1;
                    ans = max(ans, f[i % 2][j]);
                }
            }
        }
        return ans * ans;    
    }
};