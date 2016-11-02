class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size);
        
        vector<int> left2right(size);
        left2right[0] = 1;
        left2right[1] = nums[0];
        for (int i = 2; i < size; i++) {
            left2right[i] = left2right[i - 1] * nums[i - 1];
        }
        
        vector<int> right2left(size);
        right2left[size - 1] = 1;
        right2left[size - 2] = nums[size - 1];
        for (int i = size - 3; i >= 0; i--) {
            right2left[i] = right2left[i + 1] * nums[i + 1];
        }
        
        for (int i = 0; i < size; i++) {
            res[i] = left2right[i] * right2left[i];
        }
        return res;
    }
};