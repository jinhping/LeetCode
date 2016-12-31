class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() == 0) {
            return;
        } 
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                for (int j = i + 1; j < nums.size(); j++) {
                    if (nums[j] != 0) {
                        int tmp = nums[j];
                        nums[j] = 0;
                        nums[i] = tmp;
                        break;
                    }
                }
            }
        }
        return;
    }
};