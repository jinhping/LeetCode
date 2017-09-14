class Solution {
    public int maxProfit(int[] prices) {
        int res = 0;
        if (prices == null || prices.length == 0) return 0;
        int min = prices[0];
        for (int i = 0; i < prices.length; i++) {
            min = Math.min(min, prices[i]);
            if (prices[i] > min) {
                res = Math.max(res, prices[i] - min);
            }
        }
        return res;
    }
}