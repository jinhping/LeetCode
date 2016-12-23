class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i = 0; 
        int j = 0;
        int sum = 0;
        int dist = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            while (j < nums.size() && sum < s) {
                sum += nums[j];
                j++;
            }
            if (sum >= s) {
                dist = min(dist, j - i);
            }
            sum -= nums[i];
        }
        if (dist == INT_MAX) {
            return 0;
        }
        return dist;        
    }
};