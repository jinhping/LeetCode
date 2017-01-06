class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0 || prices.size() == 1) {
            return 0;
        }
        int hold1 = INT_MIN, hold2 = INT_MIN;
        int release1 = 0, release2 = 0;
        for (auto x : prices) {
            hold1 = max(-x, hold1);
            release1 = max(hold1 + x, release1);
            hold2 = max(release1 - x, hold2);
            release2 = max(hold2 + x, release2);
        }
        return release2;
    }
};