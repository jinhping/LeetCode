class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        int max = 0;
        int low = prices[0];
        for (auto x : prices) {
            if (x < low) {
                low = x;
            }
            if (x - low > max) {
                max = x - low;
            }
        }
        return max;
    }
};