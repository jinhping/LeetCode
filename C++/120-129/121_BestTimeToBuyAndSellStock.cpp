class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        int max = 0;
        int min = prices[0];
        for (int x : prices) {
            if (x < min) {
                min = x;
            }
            int tmp = x - min;
            if(tmp > max) {
                max = tmp;
            }
        }
        return max;
    }
};