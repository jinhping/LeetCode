class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        if (k >= prices.size() / 2) {
    		int maxPro = 0;
    		for (int i = 1; i < prices.size(); i++) {
    			if (prices[i] > prices[i-1])
    				maxPro += prices[i] - prices[i-1];
    		}
    		return maxPro;
    	}
    	
        vector<vector<int>> dp(k + 1, vector<int>(prices.size()));
        for (int i = 1; i < k + 1; i++) {
            int localMax = dp[i - 1][0] - prices[0];
            for (int j = 1; j < prices.size(); j++) {
                dp[i][j] = max(dp[i][j - 1], prices[j] + localMax);
                localMax = max(localMax, dp[i - 1][j] - prices[j]);
            }
        }
        return dp[k][prices.size() - 1];
    }
};