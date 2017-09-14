class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) return 0;
        int[] buys = new int[prices.length];
        int[] sells = new int[prices.length];
        int[] cooldowns = new int[prices.length];
        buys[0] = -prices[0];
        sells[0] = 0;
        cooldowns[0] = 0;
        for (int i = 1; i < prices.length; i++) {
            buys[i] = Math.max(buys[i - 1], cooldowns[i - 1] - prices[i]);
            sells[i] = buys[i - 1] + prices[i];
            cooldowns[i] = Math.max(cooldowns[i - 1], sells[i - 1]);
        }
        return Math.max(sells[prices.length - 1], cooldowns[prices.length - 1]);
    }
}