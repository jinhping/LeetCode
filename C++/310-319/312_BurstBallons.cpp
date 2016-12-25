class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        vector<int> v(n + 2);
        for (int i = 1; i < n + 1; i++) {
            v[i] = nums[i - 1];
        }
        v[0] = 1;
        v[n + 1] = 1;
        
        for (int len = 1; len <= n; len++) {
            for (int i = 1; i <= n && i + len - 1 <= n; i++) {
                int j = i + len - 1;
                for (int k = i; k <= j; k++) {
                    dp[i][j] = max(dp[i][k - 1] + dp[k + 1][j] + 
                    v[i - 1] * v[k] * v[j + 1],
                    dp[i][j]);
                }
            }
        }
        return dp[1][n];        
    }
};