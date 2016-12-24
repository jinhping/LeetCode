class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int maxherepre = nums[0];
        int minherepre = nums[0];
        int maxhere;
        int minhere;
        int maxsofar = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            maxhere = max(max(maxherepre * nums[i], minherepre * nums[i]), nums[i]);
            minhere = min(min(maxherepre * nums[i], minherepre * nums[i]), nums[i]);
            maxsofar = max(maxhere, maxsofar);
            maxherepre = maxhere;
            minherepre = minhere;
        }
        return maxsofar;
    }
};