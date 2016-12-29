class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxCover = 0;
        for (int i = 0; i < n && i <= maxCover; i++){
            if (nums[i] + i > maxCover) {
                maxCover = nums[i] + i;
            }
            if (maxCover >= n - 1) {
                return true;
            }
        }
        return false;
    }
};