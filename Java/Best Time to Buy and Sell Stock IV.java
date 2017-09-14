class Solution {
    public int maxProfit(int k, int[] prices) {
        int len = prices.length;
        if (k > len / 2) return helper(prices);
        
        int[][] t = new int[k + 1][len];
        for (int i = 1; i <= k; i++) {
            int tmpMax = -prices[0];
            for (int j = 1; j < len; j++) {
                t[i][j] = Math.max(t[i][j - 1], prices[j] + tmpMax);
                tmpMax = Math.max(tmpMax, t[i - 1][j - 1] - prices[j]);
            }
        }
        return t[k][len - 1];
    }
    
    private int helper(int[] prices) {
        int res = 0;
        for (int i = 0; i < prices.length - 1; i++) {
            res += Math.max(0, prices[i + 1] - prices[i]);
        }
        return res;
    }
}