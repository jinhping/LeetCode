class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        
        vector<int> cooldown(prices.size(),0);
        vector<int> buy(prices.size(),0);
        vector<int> sell(prices.size(),0);
        
        cooldown[0] = 0;    
        sell[0] = 0;
        buy[0] = -prices[0];

        for(int i = 1; i < prices.size();i++){
            cooldown[i] = max(cooldown[i-1], sell[i-1]);
            buy[i] = max(buy[i-1], cooldown[i-1] - prices[i]);
            sell[i] = buy[i-1] + prices[i];
        }
        return max(cooldown[prices.size()-1],sell[prices.size()-1]);
    }
};